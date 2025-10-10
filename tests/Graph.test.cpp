#define CATCH_CONFIG_MAIN
#include "../src/Graph/Graph.h"
#include <catch2/catch_test_macros.hpp>
#include <cfloat>
#include <vector>

TEST_CASE("Graph basic operations", "[Graph]") {
    SECTION("Add Vertex Increases Size") {
        auto graph = new GraphWithDFS<int>();

        REQUIRE(graph->edges.Length() == 0);

        auto vertex_id = graph->AddVertex(10);
        REQUIRE(vertex_id == 0);
        REQUIRE(graph->edges.Length() == 1);

        vertex_id = graph->AddVertex(20);
        REQUIRE(vertex_id == 1);
        REQUIRE(graph->edges.Length() == 2);

        delete graph;
    }

    SECTION("Get Vertex Returns Correct Content") {
        auto graph = new GraphWithDFS<std::string>();

        graph->AddVertex("Alice");
        graph->AddVertex("Bob");
        graph->AddVertex("Charlie");

        REQUIRE(graph->GetVertex(0) == "Alice");
        REQUIRE(graph->GetVertex(1) == "Bob");
        REQUIRE(graph->GetVertex(2) == "Charlie");

        REQUIRE_THROWS(graph->GetVertex(10));

        delete graph;
    }

    SECTION("Add Directional Edge Creates One Way Connection") {
        auto graph = new GraphWithDFS<int>();

        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);

        REQUIRE_NOTHROW(graph->AddDirectionalEdge(0, 1));
        REQUIRE_NOTHROW(graph->AddDirectionalEdge(1, 2));

        // Adding same edge twice should throw
        REQUIRE_THROWS(graph->AddDirectionalEdge(0, 1));

        // Invalid vertices should throw
        REQUIRE_THROWS(graph->AddDirectionalEdge(0, 10));
        REQUIRE_THROWS(graph->AddDirectionalEdge(10, 0));

        delete graph;
    }

    SECTION("Add Edge Creates Bidirectional Connection") {
        auto graph = new GraphWithDFS<int>();

        graph->AddVertex(0);
        graph->AddVertex(1);

        REQUIRE_NOTHROW(graph->AddEdge(0, 1));

        // Adding same edge twice should throw
        REQUIRE_THROWS(graph->AddEdge(0, 1));

        delete graph;
    }

    SECTION("Self Loop Edge Adds Only Once") {
        auto graph = new GraphWithDFS<int>();

        graph->AddVertex(0);

        REQUIRE_NOTHROW(graph->AddEdge(0, 0));

        delete graph;
    }
}

TEST_CASE("Graph Dijkstra algorithm", "[Graph][Dijkstra]") {
    SECTION("Dijkstra Single Vertex Graph") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);

        auto distances = graph->Dijkstra(0);

        REQUIRE(distances.size() == 1);
        REQUIRE(distances[0] == 0.0f);

        delete graph;
    }

    SECTION("Dijkstra Disconnected Vertices") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);

        auto distances = graph->Dijkstra(0);

        REQUIRE(distances.size() == 3);
        REQUIRE(distances[0] == 0.0f);
        REQUIRE(distances[1] == MAXFLOAT);
        REQUIRE(distances[2] == MAXFLOAT);

        delete graph;
    }

    SECTION("Dijkstra Linear Path") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);

        graph->AddDirectionalEdge(0, 1, 5.0f);
        graph->AddDirectionalEdge(1, 2, 3.0f);

        auto distances = graph->Dijkstra(0);

        REQUIRE(distances.size() == 3);
        REQUIRE(distances[0] == 0.0f);
        REQUIRE(distances[1] == 5.0f);
        REQUIRE(distances[2] == 8.0f);

        delete graph;
    }

    SECTION("Dijkstra Example From Main") {
        // Test case based on the example in main.cpp
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);
        graph->AddVertex(3);
        graph->AddVertex(4);
        graph->AddVertex(5);
        graph->AddVertex(7);

        graph->AddDirectionalEdge(0, 1, 2);
        graph->AddDirectionalEdge(0, 2, 1);
        graph->AddDirectionalEdge(0, 4, 10);

        graph->AddDirectionalEdge(1, 5, 1);

        graph->AddDirectionalEdge(2, 3, 6);
        graph->AddDirectionalEdge(2, 4, 4);

        graph->AddDirectionalEdge(4, 3, 1);

        graph->AddDirectionalEdge(5, 4, 1);

        auto distances = graph->Dijkstra(0);

        // Expected: [0, 2, 1, 5, 4, 3, MAXFLOAT]
        REQUIRE(distances.size() == 7);
        REQUIRE(distances[0] == 0.0f);
        REQUIRE(distances[1] == 2.0f);
        REQUIRE(distances[2] == 1.0f);
        REQUIRE(distances[3] == 5.0f);
        REQUIRE(distances[4] == 4.0f);
        REQUIRE(distances[5] == 3.0f);
        REQUIRE(distances[6] == MAXFLOAT);

        delete graph;
    }

    SECTION("Dijkstra With Shorter Alternative Path") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);
        graph->AddVertex(3);

        graph->AddDirectionalEdge(0, 1, 10);
        graph->AddDirectionalEdge(0, 2, 3);
        graph->AddDirectionalEdge(2, 1, 2);
        graph->AddDirectionalEdge(1, 3, 1);
        graph->AddDirectionalEdge(2, 3, 8);

        auto distances = graph->Dijkstra(0);

        REQUIRE(distances.size() == 4);
        REQUIRE(distances[0] == 0.0f);
        REQUIRE(distances[1] == 5.0f); // 0->2->1 (3+2=5) instead of 0->1 (10)
        REQUIRE(distances[2] == 3.0f);
        REQUIRE(distances[3] ==
                6.0f); // 0->2->1->3 (3+2+1=6) instead of 0->2->3 (11)

        delete graph;
    }

    SECTION("Dijkstra Invalid Source Throws") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);

        REQUIRE_THROWS(graph->Dijkstra(10));

        delete graph;
    }
}

TEST_CASE("Graph DijkstraPath algorithm", "[Graph][DijkstraPath]") {
    SECTION("Dijkstra Path Single Vertex") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);

        auto path = graph->DijkstraPath(0, 0);

        // Path to itself should be empty or just contain the vertex
        REQUIRE(path.size() == 0);

        delete graph;
    }

    SECTION("Dijkstra Path No Connection") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);

        auto path = graph->DijkstraPath(0, 1);

        // No path exists
        REQUIRE(path.size() == 0);

        delete graph;
    }

    SECTION("Dijkstra Path Direct Connection") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);

        graph->AddDirectionalEdge(0, 1, 1);

        auto path = graph->DijkstraPath(0, 1);

        REQUIRE(path.size() == 2);
        REQUIRE(path[0] == 0);
        REQUIRE(path[1] == 1);

        delete graph;
    }

    SECTION("Dijkstra Path Example From Main") {
        // Test case based on the example in main.cpp
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);
        graph->AddVertex(3);
        graph->AddVertex(4);
        graph->AddVertex(5);
        graph->AddVertex(7);

        graph->AddDirectionalEdge(0, 1, 2);
        graph->AddDirectionalEdge(0, 2, 1);
        graph->AddDirectionalEdge(0, 4, 10);

        graph->AddDirectionalEdge(1, 5, 1);

        graph->AddDirectionalEdge(2, 3, 6);
        graph->AddDirectionalEdge(2, 4, 4);

        graph->AddDirectionalEdge(4, 3, 1);

        graph->AddDirectionalEdge(5, 4, 1);

        auto path = graph->DijkstraPath(0, 4);

        // Expected path: [0, 1, 5, 4]
        REQUIRE(path.size() == 4);
        REQUIRE(path[0] == 0);
        REQUIRE(path[1] == 1);
        REQUIRE(path[2] == 5);
        REQUIRE(path[3] == 4);

        delete graph;
    }

    SECTION("Dijkstra Path Finds Shortest Not Direct") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);
        graph->AddVertex(3);

        graph->AddDirectionalEdge(0, 3, 100); // Direct but expensive
        graph->AddDirectionalEdge(0, 1, 1);
        graph->AddDirectionalEdge(1, 2, 1);
        graph->AddDirectionalEdge(2, 3, 1);

        auto path = graph->DijkstraPath(0, 3);

        // Should take the longer path in vertices but shorter in weight
        REQUIRE(path.size() == 4);
        REQUIRE(path[0] == 0);
        REQUIRE(path[1] == 1);
        REQUIRE(path[2] == 2);
        REQUIRE(path[3] == 3);

        delete graph;
    }

    SECTION("Dijkstra Path Multiple Paths Chooses Shortest") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);
        graph->AddVertex(3);

        // Two paths to vertex 3
        graph->AddDirectionalEdge(0, 1, 5);
        graph->AddDirectionalEdge(1, 3, 5); // Total: 10

        graph->AddDirectionalEdge(0, 2, 2);
        graph->AddDirectionalEdge(2, 3, 3); // Total: 5 (shorter)

        auto path = graph->DijkstraPath(0, 3);

        REQUIRE(path.size() == 3);
        REQUIRE(path[0] == 0);
        REQUIRE(path[1] == 2); // Goes through vertex 2
        REQUIRE(path[2] == 3);

        delete graph;
    }

    SECTION("Dijkstra Path Invalid Vertices Throw") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);

        REQUIRE_THROWS(graph->DijkstraPath(0, 10));
        REQUIRE_THROWS(graph->DijkstraPath(10, 0));
        REQUIRE_THROWS(graph->DijkstraPath(10, 10));

        delete graph;
    }

    SECTION("Dijkstra Path With Weights") {
        auto graph = new GraphWithDFS<std::string>();
        graph->AddVertex("A");
        graph->AddVertex("B");
        graph->AddVertex("C");
        graph->AddVertex("D");
        graph->AddVertex("E");

        graph->AddDirectionalEdge(0, 1, 4);
        graph->AddDirectionalEdge(0, 2, 2);
        graph->AddDirectionalEdge(1, 3, 5);
        graph->AddDirectionalEdge(2, 1, 1);
        graph->AddDirectionalEdge(2, 3, 8);
        graph->AddDirectionalEdge(2, 4, 10);
        graph->AddDirectionalEdge(3, 4, 2);

        auto path = graph->DijkstraPath(0, 4);

        // Optimal path: A->C->B->D->E (2+1+5+2=10) vs A->C->E (2+10=12)
        REQUIRE(path.size() == 5);
        REQUIRE(path[0] == 0); // A
        REQUIRE(path[1] == 2); // C
        REQUIRE(path[2] == 1); // B
        REQUIRE(path[3] == 3); // D
        REQUIRE(path[4] == 4); // E

        delete graph;
    }
}

TEST_CASE("Graph DFS operations", "[Graph][DFS]") {
    SECTION("DFS Single Vertex") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);

        std::vector<bool> visited(1, false);
        graph->Dfs(0, visited);

        REQUIRE(visited[0] == true);

        delete graph;
    }

    SECTION("DFS Connected Graph") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);

        graph->AddEdge(0, 1);
        graph->AddEdge(1, 2);

        std::vector<bool> visited(3, false);
        graph->Dfs(0, visited);

        REQUIRE(visited[0] == true);
        REQUIRE(visited[1] == true);
        REQUIRE(visited[2] == true);

        delete graph;
    }

    SECTION("Is Connected Returns True For Connected Vertices") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);

        graph->AddEdge(0, 1);
        graph->AddEdge(1, 2);

        REQUIRE(graph->IsConnected(0, 2) == true);
        REQUIRE(graph->IsConnected(2, 0) == true);

        delete graph;
    }

    SECTION("Is Connected Returns False For Disconnected Vertices") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);

        graph->AddEdge(0, 1);
        // Vertex 2 is isolated

        REQUIRE(graph->IsConnected(0, 2) == false);
        REQUIRE(graph->IsConnected(1, 2) == false);

        delete graph;
    }

    SECTION("Components Count Single Component") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);

        graph->AddEdge(0, 1);
        graph->AddEdge(1, 2);

        REQUIRE(graph->ComponentsCount() == 1);

        delete graph;
    }

    SECTION("Components Count Multiple Components") {
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);
        graph->AddVertex(3);
        graph->AddVertex(4);

        graph->AddEdge(0, 1);
        graph->AddEdge(3, 4);
        // Vertex 2 is isolated

        REQUIRE(graph->ComponentsCount() == 3);

        delete graph;
    }

    SECTION("Components Count Example From Main") {
        // Test case based on the example in main.cpp
        auto graph = new GraphWithDFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);
        graph->AddVertex(3);
        graph->AddVertex(4);
        graph->AddVertex(5);
        graph->AddVertex(7);

        graph->AddDirectionalEdge(0, 1, 2);
        graph->AddDirectionalEdge(0, 2, 1);
        graph->AddDirectionalEdge(0, 4, 10);

        graph->AddDirectionalEdge(1, 5, 1);

        graph->AddDirectionalEdge(2, 3, 6);
        graph->AddDirectionalEdge(2, 4, 4);

        graph->AddDirectionalEdge(4, 3, 1);

        graph->AddDirectionalEdge(5, 4, 1);

        // Should have 2 components (vertices 0-5 are connected, vertex 6 is
        // isolated)
        REQUIRE(graph->ComponentsCount() == 2);

        delete graph;
    }
}

TEST_CASE("Graph BFS operations", "[Graph][BFS]") {
    SECTION("BFS Single Vertex") {
        auto graph = new GraphWithBFS<int>();
        graph->AddVertex(0);

        std::vector<bool> visited(1, false);
        graph->Bfs(0, visited);

        REQUIRE(visited[0] == true);

        delete graph;
    }

    SECTION("BFS Connected Graph") {
        auto graph = new GraphWithBFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);

        graph->AddEdge(0, 1);
        graph->AddEdge(1, 2);

        std::vector<bool> visited(3, false);
        graph->Bfs(0, visited);

        REQUIRE(visited[0] == true);
        REQUIRE(visited[1] == true);
        REQUIRE(visited[2] == true);

        delete graph;
    }

    SECTION("Is Connected Returns True For Connected Vertices") {
        auto graph = new GraphWithBFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);

        graph->AddEdge(0, 1);
        graph->AddEdge(1, 2);

        REQUIRE(graph->IsConnected(0, 2) == true);
        REQUIRE(graph->IsConnected(2, 0) == true);

        delete graph;
    }

    SECTION("Components Count Multiple Components") {
        auto graph = new GraphWithBFS<int>();
        graph->AddVertex(0);
        graph->AddVertex(1);
        graph->AddVertex(2);
        graph->AddVertex(3);

        graph->AddEdge(0, 1);
        graph->AddEdge(2, 3);

        REQUIRE(graph->ComponentsCount() == 2);

        delete graph;
    }
}
