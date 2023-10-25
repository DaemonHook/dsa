#ifndef CROSSLIST
#define CROSSLIST

#include <vector>
#include <algorithm>

template<class DataType, class WeightType>
class Node;

//十字链表的弧节点
template<class DataType, class WeightType>
struct Arc {
    // 弧从from->node
    Node<DataType, WeightType> *fromNode, *toNode;

    WeightType weight;

    // 下一个拥有相同头/尾节点的弧
    Arc<DataType, WeightType> *fromLink = nullptr, *toLink = nullptr;

    Arc(Node<DataType, WeightType> *fromNode, Node<DataType, WeightType> *toNode, WeightType weight) : fromNode(
            fromNode), toNode(toNode),
                                                                                                       weight(weight) {}
};

//十字链表的数据节点
template<class DataType, class WeightType>
struct Node {
    DataType data;

    //第一个以此节点为出/入的弧
    Arc<DataType, WeightType> *firstFrom = nullptr, *firstTo = nullptr;

    explicit Node(DataType data) {
        this->data = data;
    }
};

//十字链表数据结构
template<class DataType, class WeightType>
struct CrossList {
    std::vector<Arc<DataType, WeightType> *> arcs;
    std::vector<Node<DataType, WeightType> *> nodes;

    CrossList() = default;

    ~CrossList() {
        for (auto p: arcs) {
            delete p;
        }
        for (auto p: nodes) {
            delete p;
        }
    }

    //添加一个新的数据节点（没有弧）
    void AddNode(DataType data) {
        nodes.push_back(new Node<DataType, WeightType>(data));
    }

    //添加一个弧
    void AddArc(DataType from, DataType to, WeightType weight) {
        Node<DataType, WeightType> *pFromNode = *std::find_if(nodes.begin(), nodes.end(), [&](Node<DataType> *p) {
            return p->data == from;
        });

        Node<DataType, WeightType> *pToNode = *std::find_if(nodes.begin(), nodes.end(), [&](Node<DataType> *p) {
            return p->data == to;
        });

        Arc<DataType, WeightType> *newArc = new Arc<DataType, WeightType>(pFromNode, pToNode);

        Arc<DataType, WeightType> *pLastSameFrom = pFromNode->firstFrom;
        while (pLastSameFrom != nullptr) {
            pLastSameFrom = pLastSameFrom->fromLink;
        }
        if (pLastSameFrom == nullptr) {
            pFromNode->firstFrom = newArc;
        } else {
            pLastSameFrom->fromLink = newArc;
        }

        Arc<DataType, WeightType> *pLastSameTo = pToNode->firstTo;
        while (pLastSameTo != nullptr) {
            pLastSameTo = pLastSameTo->toLink;
        }
        if (pLastSameTo == nullptr) {
            pToNode->firstTo = newArc;
        } else {
            pLastSameTo->toLink = newArc;
        }

    }


};

#endif
