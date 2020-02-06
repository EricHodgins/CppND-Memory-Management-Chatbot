#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
    std::cout << "GraphNode Constructor" << std::endl;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    std::cout << "GraphNode Destructor" << std::endl;
    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    std::unique_ptr<GraphEdge> newEdge(new GraphEdge(*edge));
    _parentEdges.push_back(std::move(newEdge));
    //_parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    std::unique_ptr<GraphEdge> newEdge(new GraphEdge(*edge));
    _childEdges.push_back(std::move(newEdge));
    //_childEdges.push_back(edge);
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
    std::cout << "chatbot nodes: " << _chatBot.GetCurrentNode()->GetID() << " | " << _chatBot.GetRootNode()->GetID() << std::endl;
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}
