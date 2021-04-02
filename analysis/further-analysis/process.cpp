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
    char alg[256]; lli nTubes, tubeH, nColors, seed; double nMoves, mem, t;
    while(scanf(
            "%s ,%lld,%lld,%lld,%lld,%lf,%lf,%lf\n",
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
    for(auto &p1: data){
        string alg = p1.first;
        if(alg == "astar-admissible") continue;
        for(auto &p2: p1.second){
            auto testCase = p2.first;
            get<0>(p2.second) = get<0>(data.at("astar-admissible").at(testCase))/get<0>(p2.second);
        }
    }
    cerr << "Calculated optimality for all except astar-admissible" << endl;
    {
        string alg = "astar-admissible";
        for (auto &p2: data.at(alg)) {
            get<0>(p2.second) = 1.0;
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
        map< tuple<lli,lli,lli>, size_t > count;
        map< tuple<lli,lli,lli>, double > nMovesMean, memMean, tMean;
        map< tuple<lli,lli,lli>, deque<double> > nMoves, mem, t;
        for(const auto &p2: p1.second){
            auto key = make_tuple(get<0>(p2.first), get<1>(p2.first), get<2>(p2.first));
            count[key]++;
            
            nMoves    [key].push_back(get<0>(p2.second));
            nMovesMean[key] += get<0>(p2.second);

            mem       [key].push_back(get<1>(p2.second));
            memMean   [key] += log(get<1>(p2.second));

            t         [key].push_back(get<2>(p2.second));
            tMean     [key] += log(get<2>(p2.second));
        }
        for(auto &p2: nMoves) sort(p2.second.begin(), p2.second.end());
        for(auto &p2: mem   ) sort(p2.second.begin(), p2.second.end());
        for(auto &p2: t     ) sort(p2.second.begin(), p2.second.end());
        for(const auto &p2: count){
            auto key = p2.first;
            auto c = static_cast<double>(p2.second);
            nMovesMean.at(key) /= c;
            memMean   .at(key) /= c;
            memMean   .at(key) = exp(memMean.at(key));
            tMean     .at(key) /= c;
            tMean     .at(key) = exp(tMean.at(key));
        }

        // Print
        for(const auto &p2: count){
            auto testCase = p2.first;
            cout
                << alg
                << "," << get<0>(testCase) << "," << get<1>(testCase) << "," << get<2>(testCase)
                << "," << *(nMoves.at(testCase).begin()) << "," << nMovesMean.at(testCase) << "," << *(nMoves.at(testCase).rbegin())
                << "," << *(mem   .at(testCase).begin()) << "," << memMean   .at(testCase) << "," << *(mem   .at(testCase).rbegin())
                << "," << *(t     .at(testCase).begin()) << "," << tMean     .at(testCase) << "," << *(t     .at(testCase).rbegin())
                << endl;
        }
    }

    return 0;
}
