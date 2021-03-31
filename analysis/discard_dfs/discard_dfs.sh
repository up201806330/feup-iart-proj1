MAIN=../../main
NRUNS=10

LABEL=dfs
echo -e "nTubes,tubeH,nColors,seed,$LABEL-nMoves,$LABEL-mem_b,$LABEL-t_ns" > dfs.csv
$MAIN cli $NRUNS  2 4 1 0 dfs >> dfs.csv
$MAIN cli $NRUNS  3 4 1 0 dfs >> dfs.csv
$MAIN cli $NRUNS  4 4 2 0 dfs >> dfs.csv
$MAIN cli $NRUNS  5 4 3 0 dfs >> dfs.csv
$MAIN cli $NRUNS  6 4 3 0 dfs >> dfs.csv
$MAIN cli $NRUNS  7 4 4 0 dfs >> dfs.csv

LABEL=bfs
echo -e "nTubes,tubeH,nColors,seed,$LABEL-nMoves,$LABEL-mem_b,$LABEL-t_ns" > dfs.csv
$MAIN cli $NRUNS  2 4 1 0 bfs >> bfs.csv
$MAIN cli $NRUNS  3 4 1 0 bfs >> bfs.csv
$MAIN cli $NRUNS  4 4 2 0 bfs >> bfs.csv
$MAIN cli $NRUNS  5 4 3 0 bfs >> bfs.csv
$MAIN cli $NRUNS  6 4 3 0 bfs >> bfs.csv
$MAIN cli $NRUNS  7 4 4 0 bfs >> bfs.csv

LABEL=iterative-deepening
echo -e "nTubes,tubeH,nColors,seed,$LABEL-nMoves,$LABEL-mem_b,$LABEL-t_ns" > dfs.csv
$MAIN cli $NRUNS  2 4 1 0 iterative-deepening >> iterative-deepening.csv
$MAIN cli $NRUNS  3 4 1 0 iterative-deepening >> iterative-deepening.csv
$MAIN cli $NRUNS  4 4 2 0 iterative-deepening >> iterative-deepening.csv
$MAIN cli $NRUNS  5 4 3 0 iterative-deepening >> iterative-deepening.csv
$MAIN cli $NRUNS  6 4 3 0 iterative-deepening >> iterative-deepening.csv
$MAIN cli $NRUNS  7 4 4 0 iterative-deepening >> iterative-deepening.csv

LABEL=dfs-greedy-admissible
echo -e "nTubes,tubeH,nColors,seed,$LABEL-nMoves,$LABEL-mem_b,$LABEL-t_ns" > dfs.csv
$MAIN cli $NRUNS  2 4 1 0 informed admissible dfs-greedy >> dfs-greedy-admissible.csv
$MAIN cli $NRUNS  3 4 1 0 informed admissible dfs-greedy >> dfs-greedy-admissible.csv
$MAIN cli $NRUNS  4 4 2 0 informed admissible dfs-greedy >> dfs-greedy-admissible.csv
$MAIN cli $NRUNS  5 4 3 0 informed admissible dfs-greedy >> dfs-greedy-admissible.csv
$MAIN cli $NRUNS  6 4 3 0 informed admissible dfs-greedy >> dfs-greedy-admissible.csv
$MAIN cli $NRUNS  7 4 4 0 informed admissible dfs-greedy >> dfs-greedy-admissible.csv

LABEL=greedy-admissible
echo -e "nTubes,tubeH,nColors,seed,$LABEL-nMoves,$LABEL-mem_b,$LABEL-t_ns" > dfs.csv
$MAIN cli $NRUNS  2 4 1 0 informed admissible greedy >> greedy-admissible.csv
$MAIN cli $NRUNS  3 4 1 0 informed admissible greedy >> greedy-admissible.csv
$MAIN cli $NRUNS  4 4 2 0 informed admissible greedy >> greedy-admissible.csv
$MAIN cli $NRUNS  5 4 3 0 informed admissible greedy >> greedy-admissible.csv
$MAIN cli $NRUNS  6 4 3 0 informed admissible greedy >> greedy-admissible.csv
$MAIN cli $NRUNS  7 4 4 0 informed admissible greedy >> greedy-admissible.csv

LABEL=astar-admissible
echo -e "nTubes,tubeH,nColors,seed,$LABEL-nMoves,$LABEL-mem_b,$LABEL-t_ns" > dfs.csv
$MAIN cli $NRUNS  2 4 1 0 informed admissible astar >> astar-admissible.csv
$MAIN cli $NRUNS  3 4 1 0 informed admissible astar >> astar-admissible.csv
$MAIN cli $NRUNS  4 4 2 0 informed admissible astar >> astar-admissible.csv
$MAIN cli $NRUNS  5 4 3 0 informed admissible astar >> astar-admissible.csv
$MAIN cli $NRUNS  6 4 3 0 informed admissible astar >> astar-admissible.csv
$MAIN cli $NRUNS  7 4 4 0 informed admissible astar >> astar-admissible.csv

LABEL=dfs-greedy-fh
echo -e "nTubes,tubeH,nColors,seed,$LABEL-nMoves,$LABEL-mem_b,$LABEL-t_ns" > dfs.csv
$MAIN cli $NRUNS  2 4 1 0 informed finite-horizon-heuristics 3 admissible finite-horizon dfs-greedy >> dfs-greedy-fh.csv
$MAIN cli $NRUNS  3 4 1 0 informed finite-horizon-heuristics 3 admissible finite-horizon dfs-greedy >> dfs-greedy-fh.csv
$MAIN cli $NRUNS  4 4 2 0 informed finite-horizon-heuristics 3 admissible finite-horizon dfs-greedy >> dfs-greedy-fh.csv
$MAIN cli $NRUNS  5 4 3 0 informed finite-horizon-heuristics 3 admissible finite-horizon dfs-greedy >> dfs-greedy-fh.csv
$MAIN cli $NRUNS  6 4 3 0 informed finite-horizon-heuristics 3 admissible finite-horizon dfs-greedy >> dfs-greedy-fh.csv
$MAIN cli $NRUNS  7 4 4 0 informed finite-horizon-heuristics 3 admissible finite-horizon dfs-greedy >> dfs-greedy-fh.csv

LABEL=greedy-fh
echo -e "nTubes,tubeH,nColors,seed,$LABEL-nMoves,$LABEL-mem_b,$LABEL-t_ns" > dfs.csv
$MAIN cli $NRUNS  2 4 1 0 informed finite-horizon-heuristics 3 admissible finite-horizon greedy >> greedy-fh.csv
$MAIN cli $NRUNS  3 4 1 0 informed finite-horizon-heuristics 3 admissible finite-horizon greedy >> greedy-fh.csv
$MAIN cli $NRUNS  4 4 2 0 informed finite-horizon-heuristics 3 admissible finite-horizon greedy >> greedy-fh.csv
$MAIN cli $NRUNS  5 4 3 0 informed finite-horizon-heuristics 3 admissible finite-horizon greedy >> greedy-fh.csv
$MAIN cli $NRUNS  6 4 3 0 informed finite-horizon-heuristics 3 admissible finite-horizon greedy >> greedy-fh.csv
$MAIN cli $NRUNS  7 4 4 0 informed finite-horizon-heuristics 3 admissible finite-horizon greedy >> greedy-fh.csv

LABEL=astar-fh
echo -e "nTubes,tubeH,nColors,seed,$LABEL-nMoves,$LABEL-mem_b,$LABEL-t_ns" > dfs.csv
$MAIN cli $NRUNS  2 4 1 0 informed finite-horizon-heuristics 3 admissible finite-horizon astar >> astar-fh.csv
$MAIN cli $NRUNS  3 4 1 0 informed finite-horizon-heuristics 3 admissible finite-horizon astar >> astar-fh.csv
$MAIN cli $NRUNS  4 4 2 0 informed finite-horizon-heuristics 3 admissible finite-horizon astar >> astar-fh.csv
$MAIN cli $NRUNS  5 4 3 0 informed finite-horizon-heuristics 3 admissible finite-horizon astar >> astar-fh.csv
$MAIN cli $NRUNS  6 4 3 0 informed finite-horizon-heuristics 3 admissible finite-horizon astar >> astar-fh.csv
$MAIN cli $NRUNS  7 4 4 0 informed finite-horizon-heuristics 3 admissible finite-horizon astar >> astar-fh.csv
