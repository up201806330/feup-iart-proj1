MAIN=../main
echo -e "nTubes,tubeH,nColors,seed,nMoves,mem_b,t_ns"
$MAIN cli 10  2 4 1 0 dfs
$MAIN cli 10  3 4 1 0 dfs
$MAIN cli 10  4 4 2 0 dfs
$MAIN cli 10  5 4 3 0 dfs
$MAIN cli 10  6 4 3 0 dfs
$MAIN cli 10  7 4 4 0 dfs
$MAIN cli 10  8 4 4 0 dfs
