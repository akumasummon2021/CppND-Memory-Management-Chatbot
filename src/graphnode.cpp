#include "graphedge.h"
#include "graphnode.h"

//Debug:
#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
	// Warm up:
	_chatBot = nullptr;
	delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge* edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
	//std::cout<<"GraphNode::MoveChatbotHere begins"<<std::endl;	
    _chatBot = chatbot;
	//std::cout<<"GraphNode::MoveChatbotHere middle"<<std::endl;	
    _chatBot->SetCurrentNode(this);
	//std::cout<<"GraphNode::MoveChatbotHere ends"<<std::endl;	
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
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