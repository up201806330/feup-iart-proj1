MAIN=../../main
NRUNS=1

define run_analysis
	echo "alg,nTubes,tubeH,nColors,seed,nMoves,mem_b,t_ns" > $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1 0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1 1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1 2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1 3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1 4 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1 5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1 6 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1 7 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1 8 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1 9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	
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
endef

all: bfs-processed.csv dfs-greedy-admissible-processed.csv greedy-admissible-processed.csv astar-admissible-processed.csv dfs-greedy-fh-processed.csv dfs-fh-processed.csv astar-fh-processed.csv

bfs-processed.csv: further-analysis-processed.csv
	csvgrep -c 1 -m "bfs" further-analysis-processed.csv > $@

dfs-greedy-admissible-processed.csv: further-analysis-processed.csv
	csvgrep -c 1 -m "dfs-greedy-admissible" further-analysis-processed.csv > $@

greedy-admissible-processed.csv: further-analysis-processed.csv
	csvgrep -c 1 -m "greedy-admissible" further-analysis-processed.csv > $@

astar-admissible-processed.csv: further-analysis-processed.csv
	csvgrep -c 1 -m "astar-admissible" further-analysis-processed.csv > $@

dfs-greedy-fh-processed.csv: further-analysis-processed.csv
	csvgrep -c 1 -m "dfs-greedy-fh" further-analysis-processed.csv > $@

dfs-fh-processed.csv: further-analysis-processed.csv
	csvgrep -c 1 -m "dfs-fh" further-analysis-processed.csv > $@

astar-fh-processed.csv: further-analysis-processed.csv
	csvgrep -c 1 -m "astar-fh" further-analysis-processed.csv > $@

process: process.cpp
	g++ -Wall $< -o $@

further-analysis-processed.csv: process further-analysis.csv
	./process < further-analysis.csv > /dev/null
	./process < further-analysis.csv > $@

further-analysis.csv: bfs.csv dfs-greedy-admissible.csv greedy-admissible.csv astar-admissible.csv dfs-greedy-fh.csv dfs-fh.csv astar-fh.csv
	echo "alg,nTubes,tubeH,nColors,seed,nMoves,mem_b,t_ns" > further-analysis.csv
	tail -n +2 bfs.csv                   >> further-analysis.csv
	tail -n +2 dfs-greedy-admissible.csv >> further-analysis.csv
	tail -n +2 greedy-admissible.csv     >> further-analysis.csv
	tail -n +2 astar-admissible.csv      >> further-analysis.csv
	tail -n +2 dfs-greedy-fh.csv         >> further-analysis.csv
	tail -n +2 dfs-fh.csv                >> further-analysis.csv
	tail -n +2 astar-fh.csv              >> further-analysis.csv

bfs.csv:
	$(call run_analysis,bfs,bfs)

dfs-greedy-admissible.csv:
	$(call run_analysis,informed admissible dfs-greedy,dfs-greedy-admissible)

greedy-admissible.csv:
	$(call run_analysis,informed admissible greedy,greedy-admissible)

astar-admissible.csv:
	$(call run_analysis,informed admissible astar,astar-admissible)

dfs-greedy-fh.csv:
	$(call run_analysis,informed finite-horizon-heuristics 3 admissible finite-horizon dfs-greedy,dfs-greedy-fh)

dfs-fh.csv:
	$(call run_analysis,informed finite-horizon-heuristics 3 admissible finite-horizon greedy,dfs-fh)

astar-fh.csv:
	$(call run_analysis,informed finite-horizon-heuristics 3 admissible finite-horizon astar,astar-fh)

