#include "mapping-table.hpp"
#include "stat-collector.hpp"
#include "heap-node.hpp"
#include <vector>

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
