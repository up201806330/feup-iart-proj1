MAIN=../../main
NRUNS=1

define run_analysis_short
	echo "alg,nTubes,tubeH,nColors,seed,nMoves,mem_b,t_ns" > $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1  3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1  4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1  6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1  7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1  8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1  9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1 10 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 3 4 1 0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 1 1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 1 2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 1 3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 1 4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 1 5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 1 6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 1 7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 1 8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 1 9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	
	$(MAIN) cli $(NRUNS) 4 4 2 0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 2 1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 2 2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 2 3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 2 4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 2 5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 2 6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 2 7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 2 8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 2 9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 5 4 2 0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 2 1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 2 2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 2 3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 2 4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 2 5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 2 6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 2 7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 2 8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 2 9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 6 4 3 0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 3 1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 3 2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 3 3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 3 4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 3 5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 3 6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 3 7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 3 8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 3 9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 7 4 3 0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 3 1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 3 2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 3 3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 3 4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 3 5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 3 6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 3 7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 3 8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 3 9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 8 4 4 0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 8 4 4 1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 8 4 4 2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 8 4 4 3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 8 4 4 4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 8 4 4 5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 8 4 4 6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 8 4 4 7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 8 4 4 8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 8 4 4 9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
endef

define run_analysis
	$(call run_analysis_short,$1,$2,$3)

	$(MAIN) cli $(NRUNS) 9 4 4 0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 9 4 4 1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 9 4 4 2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 9 4 4 3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 9 4 4 4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 9 4 4 5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 9 4 4 6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 9 4 4 7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 9 4 4 8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 9 4 4 9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 10 4 5 0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 10 4 5 1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 10 4 5 2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 10 4 5 3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 10 4 5 4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 10 4 5 5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 10 4 5 6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 10 4 5 7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 10 4 5 8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 10 4 5 9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 11 4 5 0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 11 4 5 1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 11 4 5 2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 11 4 5 3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 11 4 5 4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 11 4 5 5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 11 4 5 6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 11 4 5 7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 11 4 5 8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 11 4 5 9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 12 4 6 0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 12 4 6 1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 12 4 6 2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 12 4 6 3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 12 4 6 4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 12 4 6 5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 12 4 6 6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 12 4 6 7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 12 4 6 8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 12 4 6 9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 13 4 6 0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 13 4 6 1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 13 4 6 2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 13 4 6 3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 13 4 6 4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 13 4 6 5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 13 4 6 6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 13 4 6 7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 13 4 6 8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 13 4 6 9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 14 4 7 0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 14 4 7 1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 14 4 7 2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 14 4 7 3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 14 4 7 4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 14 4 7 5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 14 4 7 6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 14 4 7 7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 14 4 7 8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 14 4 7 9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 15 4 7  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 15 4 7  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 15 4 7  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 15 4 7  5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 15 4 7  6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 15 4 7  7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 15 4 7  8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 15 4 7  9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 15 4 7 11 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 15 4 7 12 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
endef

all: bfs-processed.csv dfs-greedy-admissible-processed.csv greedy-admissible-processed.csv astar-admissible-processed.csv #dfs-greedy-fh-processed.csv greedy-fh-processed.csv astar-fh-processed.csv

bfs-processed.csv: further-analysis-processed.csv
	csvgrep -c 1 -r "^bfs$$" further-analysis-processed.csv > $@

dfs-greedy-admissible-processed.csv: further-analysis-processed.csv
	csvgrep -c 1 -r "^dfs-greedy-admissible$$" further-analysis-processed.csv > $@

greedy-admissible-processed.csv: further-analysis-processed.csv
	csvgrep -c 1 -r "^greedy-admissible$$" further-analysis-processed.csv > $@

astar-admissible-processed.csv: further-analysis-processed.csv
	csvgrep -c 1 -r "^astar-admissible$$" further-analysis-processed.csv > $@

# dfs-greedy-fh-processed.csv: further-analysis-processed.csv
# 	csvgrep -c 1 -r "^dfs-greedy-fh$$" further-analysis-processed.csv > $@

# greedy-fh-processed.csv: further-analysis-processed.csv
# 	csvgrep -c 1 -r "^greedy-fh$$" further-analysis-processed.csv > $@

# astar-fh-processed.csv: further-analysis-processed.csv
# 	csvgrep -c 1 -r "^astar-fh$$" further-analysis-processed.csv > $@

process: process.cpp
	g++ -Wall $< -o $@

further-analysis-processed.csv: process further-analysis.csv
	./process < further-analysis.csv > $@

further-analysis.csv: bfs.csv dfs-greedy-admissible.csv greedy-admissible.csv astar-admissible.csv #dfs-greedy-fh.csv greedy-fh.csv astar-fh.csv
	echo "alg,nTubes,tubeH,nColors,seed,nMoves,mem_b,t_ns" > further-analysis.csv
	tail -n +2 bfs.csv                   >> further-analysis.csv
	tail -n +2 dfs-greedy-admissible.csv >> further-analysis.csv
	tail -n +2 greedy-admissible.csv     >> further-analysis.csv
	tail -n +2 astar-admissible.csv      >> further-analysis.csv
#	tail -n +2 dfs-greedy-fh.csv         >> further-analysis.csv
#	tail -n +2 greedy-fh.csv             >> further-analysis.csv
#	tail -n +2 astar-fh.csv              >> further-analysis.csv

bfs.csv:
	$(call run_analysis_short,bfs,bfs)

dfs-greedy-admissible.csv:
	$(call run_analysis,informed admissible dfs-greedy,dfs-greedy-admissible)

greedy-admissible.csv:
	$(call run_analysis,informed admissible greedy,greedy-admissible)

astar-admissible.csv:
	$(call run_analysis,informed admissible astar,astar-admissible)

# dfs-greedy-fh.csv:
# 	$(call run_analysis,informed finite-horizon-heuristics 3 admissible finite-horizon dfs-greedy,dfs-greedy-fh)

# greedy-fh.csv:
# 	$(call run_analysis,informed finite-horizon-heuristics 3 admissible finite-horizon greedy,greedy-fh)

# astar-fh.csv:
# 	$(call run_analysis,informed finite-horizon-heuristics 3 admissible finite-horizon astar,astar-fh)

