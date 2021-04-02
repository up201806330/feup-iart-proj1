#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

const double BYTES_TO_MB = 1.0/1000000.0;
const double NANOS_TO_MILLIS = 1.0/1000000.0;
const double INF = 1000000000000.0;

int main(int argc, char *argv[]){
    // Collect data
    char header[256];
    scanf("%s\n", header);
    map<string, map<tuple<lli,lli,lli,lli>, tuple<double,double,double>>> data;
    char alg[256]; lli nTubes, tubeH, nColors, seed, nMoves, mem, t;
    while(scanf(
            "%s ,%lld,%lld,%lld,%lld,%lld,%lld,%lld\n",
            alg, &nTubes, &tubeH, &nColors, &seed, &nMoves, &mem, &t
    ) != -1){
        data[string(alg)][make_tuple(nTubes, tubeH, nColors, seed)] = make_tuple(
            nMoves,
            static_cast<double>(mem) * BYTES_TO_MB,
            static_cast<double>(t) * NANOS_TO_MILLIS
        );
    }
    cerr << "Collected data" << endl;
    // Calculate optimality
    for(const auto &p1: data){
        string alg = p1.first;
        if(alg == "astar-admissible") continue;
        for(const auto &p2: data.at(alg)){
            tuple<lli,lli,lli,lli> testCase = p2.first;
            get<1>(data.at(alg).at(testCase)) /= get<1>(data.at("astar-admissible").at(testCase));
        }
    }
    cerr << "Calculated optimality for all except astar-admissible" << endl;
    {
        string alg = "astar-admissible";
        for(const auto &p: data) cerr << p.first << endl;
        for (const auto &p2: data.at(alg)) {
            tuple<lli, lli, lli, lli> testCase = p2.first;
            get<1>(data.at(alg).at(testCase)) = 1;
        }
    }
    cerr << "Calculated optimality" << endl;

    // Print header
    cout
            << "alg,nTubes,tubeH,nColors,"
            << "nMovesMin,nMovesMean,nMovesMax,"
            << "memMBMin,memMBMean,memMBMax,"
            << "tmsMin,tmsMean,tmsMax"
            << endl;

    // Calculate averages, mins, maxs
    for(const auto &p1: data){
        string alg = p1.first;
        map<tuple<lli,lli,lli>, size_t> count;
        map<tuple<lli,lli,lli>,double> nMovesMin, nMovesMean, nMovesMax;
        map<tuple<lli,lli,lli>,double> memMin, memMean, memMax;
        map<tuple<lli,lli,lli>,double> tMin, tMean, tMax;
        for(const auto &p2: p1.second){
            auto key = make_tuple(get<0>(p2.first), get<1>(p2.first), get<2>(p2.first));
            if(!nMovesMin.count(key)) nMovesMin[key] = +INF;
            if(!nMovesMax.count(key)) nMovesMax[key] = -INF;
            if(!memMin   .count(key)) memMin   [key] = +INF;
            if(!memMax   .count(key)) memMax   [key] = -INF;
            if(!tMin     .count(key)) tMin     [key] = +INF;
            if(!tMax     .count(key)) tMax     [key] = -INF;

            count[key]++;
            
            nMovesMin [key] = min(nMovesMin[key], get<0>(p2.second));
            nMovesMean[key] += get<0>(p2.second);
            nMovesMax [key] = max(nMovesMax[key], get<0>(p2.second));

            memMin    [key] = min(memMin   [key], get<1>(p2.second));
            memMean   [key] += get<1>(p2.second);
            memMax    [key] = max(memMax   [key], get<1>(p2.second));

            tMin      [key] = min(tMin     [key], get<2>(p2.second));
            tMean     [key] += get<2>(p2.second);
            tMax      [key] = max(tMax     [key], get<2>(p2.second));
        }
        for(const auto &p2: count){
            auto key = p2.first;
            auto c = static_cast<double>(p2.second);
            nMovesMean.at(key) /= c;
            memMean   .at(key) /= c;
            tMean     .at(key) /= c;
        }

        // Print
        for(const auto &p2: count){
            auto testCase = p2.first;
            cout
                << alg
                << "," << get<0>(testCase) << "," << get<1>(testCase) << "," << get<2>(testCase)
                << "," << nMovesMin.at(testCase) << "," << nMovesMean.at(testCase) << "," << nMovesMax.at(testCase)
                << "," << nMovesMin.at(testCase) << "," << nMovesMean.at(testCase) << "," << nMovesMax.at(testCase)
                << "," << nMovesMin.at(testCase) << "," << nMovesMean.at(testCase) << "," << nMovesMax.at(testCase)
                << endl;
        }
    }

    return 0;
}
