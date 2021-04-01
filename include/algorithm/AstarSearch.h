// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#pragma once

#include "algorithm/SearchStrategy.h"
#include "algorithm/heuristics/Heuristic.h"

#include <set>

/**
 * @brief Best-first, A* search.
 *
 * A* is a pathfinding algorithm generally used for robotics, due to its considerable performance improvement relative
 * to other pathfinding algorithms. It is an informed search method, and works similarly to Dijkstra's algorithm, with
 * a small difference:
 * - Dijkstra's algorithm keeps, for each state in the boundary (queue), the distance from the origin to that state, and
 * expands on each iteration the state with least distance from the origin.
 * - A* algorithm keeps, for each state in the boundary, the distance from the origin plus the value of an
 * estimate/heuristic function h of the distance to a solution state (i.e., the estimated total distance of a solution
 * going through that state), and expands on each iteration the state with least estimated total distance.
 *
 * This means the A* algorithm can use additional information from the problem context to expand some states first, and
 * reach a solution faster.
 *
 * For instance, a map can be interpreted as a graph and Dijkstra's algorithm can be used to
 * find the shortest distance path between two nodes, but there are a set of inherent restrictions to a map that are
 * lost if said map is converted to a pure graph; namely, if the graph represents a map, it is trivial that the least
 * distance from a node to another is the length of a straight line from a node to another, so a possible heuristic that
 * the A* algorithm could use for additional information is the distance in a straight line between any node and the
 * final state.
 *
 * For the A* algorithm, an heuristic must be an estimate of the number of moves from a state to any
 * final (solution) state, unlike the description given in Heuristic (which says it is not required to interpret the
 * score as the number of moves to any final state, as the score is only required to be a means of ranking states).
 *
 * If the provided heuristic is admissible [@see AdmissibleHeuristic] (not necessarily an instance of AdmissibleHeuristic, as that is a particular
 * admissible heuristic; there may be other admissible heuristics), then the A* algorithm is guaranteed to give an
 * optimal solution.
 *
 * The larger the scores the heuristic returns, the least nodes will be inspected on average, although the solution
 * is only optimal if the heuristic is admissible. Thus, for an optimal solution, one must aim at designing an heuristic
 * which is admissible (i.e. always returns a score less than or equal to the minimum cost path to a solution) but
 * returns scores as close to the actual minimum cost path as possible.
 *
 * - If the heuristic always returns exactly the minimum cost, the complexity is linear in the length of the solution
 * path O(P) (which is bound to O(V)) if the A* algorithm breaks ties between similar-cost nodes by expanding the most recently expanded node.
 * - If the heuristic is not admissible, the average time complexity is the length of the solution path (which might be
 * longer than the optimal solution).
 * - If the heuristic is admissible and quite close to the actual minimum cost (i.e., if the heuristic is pretty good),
 * the time complexity is on average the length of the solution path, and is bound between O(P) and O(P²).
 * - If the heuristic is pretty bad, the time complexity is O(E + V log V). This is actually Dijkstra's algorithm
 * complexity using a priority queue, as Dijkstra's algorithm is a particular case of the A* algorithm with h = 0.
 */
class AstarSearch: public SearchStrategy {
private:
    const Heuristic *h = nullptr;
    std::deque<GameboardModel::Move> solution;
public:
    /**
     * @brief Construct A* search from a heuristic.
     *
     * The heuristic is used to estimate the number of moves from the current state to any final state.
     *
     * @param heuristic Heuristic
     */
    explicit AstarSearch(const Heuristic *heuristic);
    void initialize(const GameboardModel &gameboard) override;
    GameboardModel::Move next() override;
    ~AstarSearch() override;
};
