MAIN=../main
NRUNS=10

echo -e "nTubes,tubeH,nColors,seed,nMoves,mem_b,t_ns"

$MAIN cli $NRUNS  2 4 1 0 dfs
$MAIN cli $NRUNS  3 4 1 0 dfs
$MAIN cli $NRUNS  4 4 2 0 dfs
$MAIN cli $NRUNS  5 4 3 0 dfs
$MAIN cli $NRUNS  6 4 3 0 dfs
$MAIN cli $NRUNS  7 4 4 0 dfs

$MAIN cli $NRUNS  2 4 1 0 bfs
$MAIN cli $NRUNS  3 4 1 0 bfs
$MAIN cli $NRUNS  4 4 2 0 bfs
$MAIN cli $NRUNS  5 4 3 0 bfs
$MAIN cli $NRUNS  6 4 3 0 bfs
$MAIN cli $NRUNS  7 4 4 0 bfs

$MAIN cli $NRUNS  2 4 1 0 iterative-deepening
$MAIN cli $NRUNS  3 4 1 0 iterative-deepening
$MAIN cli $NRUNS  4 4 2 0 iterative-deepening
$MAIN cli $NRUNS  5 4 3 0 iterative-deepening
$MAIN cli $NRUNS  6 4 3 0 iterative-deepening
$MAIN cli $NRUNS  7 4 4 0 iterative-deepening
