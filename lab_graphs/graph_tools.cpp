/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"
using namespace std;
/**
 * Does a BFS of a graph, keeping track of the minimum
 *  weight edge seen so far.
 */
Edge GraphTools::BFS(Graph& graph, Vertex start, Edge & curr_MinEdge)
{
  queue<Vertex> q;
  graph.setVertexLabel(start, "VISITED");
  q.push(start);
  //Edge curr_MinEdge_temp = curr_MinEdge;
  while (!q.empty())
  {
    Vertex temp = q.front();
    q.pop();
    for(auto & w : graph.getAdjacent(temp))
    {
      if (graph.getVertexLabel(w) == "UNEXPLORED")
      {
        graph.setEdgeLabel(temp, w, "DISCOVERY");
        graph.setVertexLabel(w, "VISITED");
        q.push(w);
        if (graph.getEdge(temp,w) < curr_MinEdge)
          curr_MinEdge = graph.getEdge(temp,w);
      }
      else if (graph.getEdgeLabel(temp, w) == "UNEXPLORED")
      {
        graph.setEdgeLabel(temp, w, "CROSS");
        if (graph.getEdge(temp,w) < curr_MinEdge)
          curr_MinEdge = graph.getEdge(temp,w);
      }
    }
  }

  return curr_MinEdge;
}

/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph& graph)
{
    //Initially label vertices and edges as unvisited.
    vector<Edge> edges = graph.getEdges();
    for(auto & it : edges)
      graph.setEdgeLabel(it.source, it.dest, "UNEXPLORED");
    vector<Vertex> vertices = graph.getVertices();
    for(auto & it2 : vertices)
      graph.setVertexLabel(it2, "UNEXPLORED");

    Edge MinEdge = edges[0];
    BFS(graph, graph.getStartingVertex(), MinEdge);

    graph.setEdgeLabel(MinEdge.source, MinEdge.dest, "MIN");
    return graph.getEdgeWeight(MinEdge.source, MinEdge.dest);
}



/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph& graph, Vertex start, Vertex end)
{
    //TODO: YOUR CODE HERE
    vector<Edge> edges = graph.getEdges();
    for(auto & it : edges)
      graph.setEdgeLabel(it.source, it.dest, "UNEXPLORED");
    vector<Vertex> vertices = graph.getVertices();
    for(auto & it2 : vertices)
      graph.setVertexLabel(it2, "UNEXPLORED");

    unordered_map<Vertex, Vertex> path_map;
    queue<Vertex> q;
    graph.setVertexLabel(start, "VISITED");
    q.push(start);

    while (!q.empty())
    {
      Vertex temp = q.front();
      q.pop();
      for(auto & w : graph.getAdjacent(temp))
      {
        if (graph.getVertexLabel(w) == "UNEXPLORED")
        {
          graph.setEdgeLabel(temp, w, "DISCOVERY");
          graph.setVertexLabel(w, "VISITED");
          q.push(w);
          path_map[w] = temp;
        }
        else if (graph.getEdgeLabel(temp, w) == "UNEXPLORED")
        {
          graph.setEdgeLabel(temp, w, "CROSS");
        }
      }
    }

    //back count
    int counter = 0;
    while (end != start)
    {
      graph.setEdgeLabel(path_map[end], end, "MINPATH");
      end = path_map[end];
      counter++;
    }

    return counter;
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the dsets.h and dsets.cpp .
 * @note You may call std::sort instead of creating a priority queue.
 */
void GraphTools::findMST(Graph& graph)
{
  vector<Edge> edges = graph.getEdges();
  vector<Vertex> vertices = graph.getVertices();
  size_t vertex_size = vertices.size();
  DisjointSets graph_set;
  graph_set.addelements(vertex_size);

  unordered_map<Vertex, int> path_map;
  int c = 0;
  for (auto& it : vertices)
  {
    path_map[it] = c;
    c++;
  }

  sort(edges.begin(), edges.end());
  size_t vertex_counter = 0;
  size_t edge_counter = 0;
  while(edge_counter < vertex_size-1)
  {
    Edge temp = edges[vertex_counter];
    if(graph_set.find(path_map[temp.source]) != graph_set.find(path_map[temp.dest]))
    {
      graph.setEdgeLabel(temp.source, temp.dest, "MST");
      graph_set.setunion(graph_set.find(path_map[temp.source]), graph_set.find(path_map[temp.dest]));
      edge_counter++;
    }
  vertex_counter++;
  }
}
