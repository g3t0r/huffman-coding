#include "mapping-table.hpp"
#include "stat-collector.hpp"
#include "heap-node.hpp"
#include <vector>

std::ostream &operator<<(std::ostream &os, const MappingTable &mt)
{
    for (int i = 0; i < 128; i++)
    {
        std::string code = mt.get(i);
        if (code.empty())
            continue;

        os <<  (char)i << "(" << i << ")" << "=" << code << std::endl;
    }
    return os;
}

HeapNode *generateTree(const char *txt);
void generateMappingForTree(MappingTable *mp, HeapNode *root, std::string s);
void MappingTable::put(char c, std::string s)
{
    map[c] = s;
}
std::string MappingTable::get(char c) const
{
    return map[c];
}
MappingTable *MappingTable::generateMappingTable(const char *txt)
{
    HeapNode *root = generateTree(txt);
    MappingTable *mp = new MappingTable();
    generateMappingForTree(mp, root, "");
    return mp;
}

void generateMappingForTree(MappingTable *mp, HeapNode *root, std::string s)
{
    if (root->getLeft() == nullptr && root->getRight() == nullptr)
    {
        mp->put(root->getCharacter(), s);
    }

    if (root->getLeft() != nullptr)
    {
        std::string local = s;
        local.append("0");
        generateMappingForTree(mp, root->getLeft(), local);
    }

    if (root->getRight() != nullptr)
    {
        std::string local = s;
        local.append("1");
        generateMappingForTree(mp, root->getRight(), local);
    }
}

HeapNode *generateTree(const char *txt)
{
    CharacterCountMap *countMap = CharacterCountMap::fromText(txt);
    std::vector<HeapNode *> list = {};
    for (int i = 0; i < 128; i++)
    {
        int o = countMap->get(i);
        if (o <= 0)
            continue;

        list.push_back(new HeapNode(i, o));
    }

    HeapNode *root = buildTree(list);
    return root;
}
