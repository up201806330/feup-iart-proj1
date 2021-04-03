MAIN=../../../main
NRUNS=1

define run_analysis
	echo "alg,nTubes,tubeH,nColors,seed,nMoves,mem_b,t_ns" > $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 2 4 1  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	
	$(MAIN) cli $(NRUNS) 3 4 1  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 1  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 1  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 2  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 2  3 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 3 4 2  9 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 4 4 1  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 1  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 1  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 2  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 2  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 2  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 3  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 3  5 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 4 4 3 11 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	
	$(MAIN) cli $(NRUNS) 5 4 1  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 1  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 1  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 2  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 2  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 2  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 3  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 3  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 3  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 4 12 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 4 34 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 5 4 4 43 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 6 4 1  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 1  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 1  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 2  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 2  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 2  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 3  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 3  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 3  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 4  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 4  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 4  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 5 47 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 5 48 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 6 4 5 59 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv

	$(MAIN) cli $(NRUNS) 7 4 1  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 1  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 1  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 2  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 2  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 2  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 3  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 3  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 3  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 4  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 4  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 4  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 5  0 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 5  1 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 5  2 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 6 144 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 6 256 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
	$(MAIN) cli $(NRUNS) 7 4 6 401 $(1) | awk '{print "$2 ,"$$1}' >> $(2).csv
endef

all: bfs-processed.csv dfs-greedy-admissible-processed.csv greedy-admissible-processed.csv astar-admissible-processed.csv astar-nonadmissible-processed.csv

%-2.csv: %.csv
	csvgrep -c nTubes -m 2 $< > $@

%-3.csv: %.csv
	csvgrep -c nTubes -m 3 $< > $@

%-4.csv: %.csv
	csvgrep -c nTubes -m 4 $< > $@

%-5.csv: %.csv
	csvgrep -c nTubes -m 5 $< > $@

%-6.csv: %.csv
	csvgrep -c nTubes -m 6 $< > $@

%-7.csv: %.csv
	csvgrep -c nTubes -m 7 $< > $@

bfs-processed.csv: bfs.csv process
	./process < $< > $@
	make bfs-processed-2.csv
	make bfs-processed-3.csv
	make bfs-processed-4.csv
	make bfs-processed-5.csv
	make bfs-processed-6.csv
	make bfs-processed-7.csv

dfs-greedy-admissible-processed.csv: dfs-greedy-admissible.csv process
	./process < $< > $@
	make dfs-greedy-admissible-processed-2.csv
	make dfs-greedy-admissible-processed-3.csv
	make dfs-greedy-admissible-processed-4.csv
	make dfs-greedy-admissible-processed-5.csv
	make dfs-greedy-admissible-processed-6.csv
	make dfs-greedy-admissible-processed-7.csv

greedy-admissible-processed.csv: greedy-admissible.csv process
	./process < $< > $@
	make greedy-admissible-processed-2.csv
	make greedy-admissible-processed-3.csv
	make greedy-admissible-processed-4.csv
	make greedy-admissible-processed-5.csv
	make greedy-admissible-processed-6.csv
	make greedy-admissible-processed-7.csv

astar-admissible-processed.csv: astar-admissible.csv process
	./process < $< > $@
	make astar-admissible-processed-2.csv
	make astar-admissible-processed-3.csv
	make astar-admissible-processed-4.csv
	make astar-admissible-processed-5.csv
	make astar-admissible-processed-6.csv
	make astar-admissible-processed-7.csv

astar-nonadmissible-processed.csv: astar-nonadmissible.csv process
	./process < $< > $@
	make astar-nonadmissible-processed-2.csv
	make astar-nonadmissible-processed-3.csv
	make astar-nonadmissible-processed-4.csv
	make astar-nonadmissible-processed-5.csv
	make astar-nonadmissible-processed-6.csv
	make astar-nonadmissible-processed-7.csv

process: ../process.cpp
	g++ -Wall $< -o $@

bfs.csv:
	$(call run_analysis,bfs,bfs)

dfs-greedy-admissible.csv:
	$(call run_analysis,informed admissible dfs-greedy,dfs-greedy-admissible)

greedy-admissible.csv:
	$(call run_analysis,informed admissible greedy,greedy-admissible)

astar-admissible.csv:
	$(call run_analysis,informed admissible astar,astar-admissible)

astar-nonadmissible.csv:
	$(call run_analysis,informed nonadmissible 1.000000001 astar,astar-nonadmissible)
