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
    map<string, map<tuple<lli,lli,lli,lli>, tuple<lli,double,double>>> data;
    char alg[256]; lli nTubes, tubeH, nColors, seed, nMoves; double mem, t;
    while(scanf(
            "%s ,%lld,%lld,%lld,%lld,%lld,%lf,%lf\n",
            alg, &nTubes, &tubeH, &nColors, &seed, &nMoves, &mem, &t
    ) != -1){
        data[string(alg)][make_tuple(nTubes, tubeH, nColors, seed)] = make_tuple(
            nMoves,
            static_cast<double>(mem) * BYTES_TO_MB,
            static_cast<double>(t) * NANOS_TO_MILLIS
        );
    }
    cerr << "Collected data" << endl;
    
    // Print header
    cout
            << "alg,nTubes,tubeH,nColors,"
            << "memMBMean,"
            << "tmsMean"
            << endl;

    // Calculate averages, mins, maxs
    for(const auto &p1: data){
        string alg = p1.first;
        map< tuple<lli,lli,lli>, size_t > count;
        map< tuple<lli,lli,lli>, double > memMean, tMean;
        for(const auto &p2: p1.second){
            auto key = make_tuple(get<0>(p2.first), get<1>(p2.first), get<2>(p2.first));
            count[key]++;
            
            memMean   [key] += log(get<1>(p2.second));
            tMean     [key] += log(get<2>(p2.second));
        }
        for(const auto &p2: count){
            auto key = p2.first;
            auto c = static_cast<double>(p2.second);
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
                << "," << memMean.at(testCase)
                << "," << tMean  .at(testCase)
                << endl;
        }
    }

    return 0;
}
