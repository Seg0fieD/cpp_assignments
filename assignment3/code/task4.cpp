#define CATCH_CONFIG_MAIN 
#include "catch.hpp"

#include "graph.hpp"

template <typename VertexProp>
Graph<VertexProp>::Graph(){

}

template <typename VertexProp>
Graph<VertexProp>::Graph(std::size_t num_vertices){
    adj_mat_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++)
    {
        adj_mat_[i].resize(num_vertices);
    }
    for(int i = 0 ; i < num_vertices; i++){
        for(int j= 0 ; j< num_vertices; j++){
            adj_mat_[i][j] = 0;
        }
    }    
}

template <typename VertexProp>
std::size_t Graph<VertexProp>::add_vertex(VertexProp &&prop){
    for(int i = 0 ; i < this->num_vertices(); i++){
        if(this->vertex_props_[i] == prop){
            return i;
        }
    }
    // int num_vertices = adj_mat_.size()+1;
    // adj_mat_.resize(num_vertices);
    // for (int i = 0; i < num_vertices; i++)
    // {
    //     adj_mat_[i].resize(num_vertices);
    // }
    // for(int i = 0; i < num_vertices;i++){
    //     adj_mat_[num_vertices-1][i] = 0;
    // }
    // for(int i = 0; i < num_vertices;i++){
    //     adj_mat_[i][num_vertices-1] = 0;
    // }
    vertex_props_.pushback(prop);
    return vertex_props_.size()-1;
}

template <typename VertexProp>
bool Graph<VertexProp>::add_edge(const std::size_t v_idx1, const std::size_t v_idx2){
    if(v_idx1<0 || v_idx2<0 || v_idx1>this->num_vertices()-1 || v_idx2>this->num_vertices()-1){
        return 0;
    }
    //The edge is made from v_idx1 to v_idx2
    if(adj_mat_[v_idx1][v_idx2]){
        return 0;
    }
    else{
        adj_mat_[v_idx1][v_idx2] = 1;
        return 1;
    }
}

template <typename VertexProp>
bool Graph<VertexProp>::remove_edge(const std::size_t v_idx1, const std::size_t v_idx2){
    //The edge from v_idx1 to v_idx2 is removed possibly.
    if(v_idx1<0 || v_idx2<0 || v_idx1>this->num_vertices()-1 || v_idx2>this->num_vertices()-1){
        return 0;
    }
    if(adj_mat_[v_idx1][v_idx2]){
        adj_mat_[v_idx1][v_idx2] = 0;
        return 1;
    }
    else{
        return 0;
    }
}

template <typename VertexProp>
bool Graph<VertexProp>::has_edge(const std::size_t v_idx1, const std::size_t v_idx2) const{
    // Checks the edge from v_idx1 to v_idx2
    if(v_idx1<0 || v_idx2<0 || v_idx1>this->num_vertices()-1 || v_idx2>this->num_vertices()-1){
        return 0;
    }
    return adj_mat_[v_idx1][v_idx2];
}

template <typename VertexProp>
bool Graph<VertexProp>::path_exists(const std::size_t v_idx, const std::size_t v_idx2) const{
 return 1;
}

template <typename VertexProp>
VertexProp &Graph<VertexProp>::get_vertex(const std::size_t v_idx){
    if(v_idx<0 || v_idx>this->num_vertices()-1){
        return {};
    }
    return vertex_props_[v_idx];
}

template <typename VertexProp>
const VertexProp &Graph<VertexProp>::get_vertex(const std::size_t v_idx) const{
    if(v_idx<0 || v_idx>this->num_vertices()-1){
        return {};
    }
    return vertex_props_[v_idx];
}

template <typename VertexProp>
std::size_t Graph<VertexProp>::num_vertices() const{
    return vertex_props_.size();
}

template <typename VertexProp>
std::size_t Graph<VertexProp>::num_edges() const{
    int sum = 0;
    for (int i = 0; i < this->num_vertices(); i++){
        for(int j = 0; j < this->num_vertices(); j++){
            sum += adj_mat_[i][j];
        }
    }
    return sum;
}

template <typename VertexProp>
std::list<std::size_t> Graph<VertexProp>::get_neighbors(const std::size_t v_idx) const{
    if(v_idx<0 || v_idx>this->num_vertices()-1){
        return {};
    }
    std::list<std::size_t> neighbors;
    for(auto i = 0; i < this-> num_vertices(); i++){
        if(adj_mat_[v_idx][i]){
            neighbors.push_back(i);
        }
    }
    return neighbors; 
}

template <typename VertexProp>
std::list<std::size_t> Graph<VertexProp>::get_undirected_neighbors(const std::size_t v_idx) const{
    if(v_idx<0 || v_idx>this->num_vertices()-1){
        return {};
    }
    std::list<std::size_t> u_neighbors;
    for(std::size_t i = 0; i < this-> num_vertices(); i++){
        if(adj_mat_[v_idx][i]){
            u_neighbors.push_back(i);
        }
    }
    for(std::size_t i = 0; i < this-> num_vertices(); i++){
        if(adj_mat_[i][v_idx]){
            int flag = 0;
            for(auto x : u_neighbors){
                if(x==i){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                u_neighbors.push_back(i);      
            }
        }
    }
    return u_neighbors;
}
//Adding useless comment line to re trigger pipeline

struct prop {
    int x;
    prop(int n) : x(n){}
};


TEST_CASE("add_edge valid"){
    Graph<prop> g(6);

    prop e1(0);
    prop e2(0);
    prop e3(0);
    prop e4(0);
    prop e5(0);
    prop e6(0);

    REQUIRE(g.add_vertex(e1));

    REQUIRE(g.add_edge(1,3));
    REQUIRE(g.add_edge(2,4));
    REQUIRE(g.add_edge(2,5));
    REQUIRE(g.add_edge(1,3));
    REQUIRE(g.add_edge(4,5));
    REQUIRE(g.add_edge(5,4));
    REQUIRE(g.add_edge(3,2));
    REQUIRE(g.add_edge(2,4));
    REQUIRE(g.add_edge(5,1));

    REQUIRE(g.num_vertices() == 6);
    REQUIRE(g.num_edges() == 9);


}

TEST_CASE("add_edge invalid"){
}

TEST_CASE("remove_edge valid"){
}
TEST_CASE("remove_edge invalid"){
}

TEST_CASE("add_vertex valid"){
}
TEST_CASE("add_vertex invalid"){
}

TEST_CASE("get_neighbors valid") {
}
TEST_CASE("get_neighbors invalid") {
}

TEST_CASE("get_undirected_neighbors valid") {
}
TEST_CASE("get_undirected_neighbors invalid") {
}

TEST_CASE("get_vertex valid"){
}
TEST_CASE("get_vertex invalid"){
}

TEST_CASE("has_edge valid"){
}
TEST_CASE("has_edge invalid"){
}

TEST_CASE("num_edges valid"){
}
TEST_CASE("num_edges invalid"){
}

TEST_CASE("num_vertices valid"){
}
TEST_CASE("num_vertices invalid"){
}

TEST_CASE("path_exists valid"){
}
TEST_CASE("path_exists invalid"){
}

