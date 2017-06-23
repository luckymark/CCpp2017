#include <vector>

class Node {
    public:
        Node(int value);
        virtual ~Node();
        void append(Node *node);
        int count();
        Node* getParent();
        int getValue();
    protected:
    private:
        int data;
        int childCount = 0;
        std::vector<Node*> childrenNodes;
        Node *parent;
};
