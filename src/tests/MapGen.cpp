
#include "../Map.hpp"


int main(int argc, char** argv)
{

    {
        Map map;

        RegionNode r1 (RegionType::SEA,      MapToken::NONE,     {RegionFeature::NONE},   false);
        RegionNode r2 (RegionType::FARM,     MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, false);
        RegionNode r3 (RegionType::FOREST,   MapToken::NONE,     {RegionFeature::MINE},   false);
        RegionNode r4 (RegionType::MARSH,    MapToken::NONE,     {RegionFeature::CAVERN}, true);
        RegionNode r5 (RegionType::HILL,     MapToken::NONE,     {RegionFeature::NONE},   false);
        RegionNode r6 (RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::MINE, RegionFeature::CAVERN}, false);
        RegionNode r7 (RegionType::HILL,     MapToken::NONE,     {RegionFeature::NONE},   true);
        RegionNode r8 (RegionType::SEA,      MapToken::NONE,     {RegionFeature::NONE},   false);
        RegionNode r9 (RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::NONE},   false);
        RegionNode r10(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   false);
        RegionNode r11(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, false);
        RegionNode r12(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   true);
        RegionNode r13(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::NONE},   false);
        RegionNode r14(RegionType::FARM,     MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, false);
        RegionNode r15(RegionType::HILL,     MapToken::NONE,     {RegionFeature::CAVERN}, false);
        RegionNode r16(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::MINE},   false);
        RegionNode r17(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, true);
        RegionNode r18(RegionType::HILL,     MapToken::NONE,     {RegionFeature::CAVERN}, false);
        RegionNode r19(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::MINE},   false);
        RegionNode r20(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::NONE},   false);
        RegionNode r21(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::NONE},   false);
        RegionNode r22(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::NONE},   false);
        RegionNode r23(RegionType::SEA,      MapToken::NONE,     {RegionFeature::NONE},   false);

        Vertex v1 =  map.addRegion(r1);
        Vertex v2 =  map.addRegion(r2);
        Vertex v3 =  map.addRegion(r3);
        Vertex v4 =  map.addRegion(r4);
        Vertex v5 =  map.addRegion(r5);
        Vertex v6 =  map.addRegion(r6);
        Vertex v7 =  map.addRegion(r7);
        Vertex v8 =  map.addRegion(r8);
        Vertex v9 =  map.addRegion(r9);
        Vertex v10 = map.addRegion(r10);
        Vertex v11 = map.addRegion(r11);
        Vertex v12 = map.addRegion(r12);
        Vertex v13 = map.addRegion(r13);
        Vertex v14 = map.addRegion(r14);
        Vertex v15 = map.addRegion(r15);
        Vertex v16 = map.addRegion(r16);
        Vertex v17 = map.addRegion(r17);
        Vertex v18 = map.addRegion(r18);
        Vertex v19 = map.addRegion(r19);
        Vertex v20 = map.addRegion(r20);
        Vertex v21 = map.addRegion(r21);
        Vertex v22 = map.addRegion(r22);
        Vertex v23 = map.addRegion(r23);

        map.connectRegion(v1, v2);
        map.connectRegion(v2, v3);
        map.connectRegion(v3, v4);
        map.connectRegion(v4, v5);
        map.connectRegion(v1, v6);
        map.connectRegion(v2, v6);
        map.connectRegion(v6, v7);
        map.connectRegion(v7, v2);
        map.connectRegion(v7, v3);
        map.connectRegion(v7, v8);
        map.connectRegion(v8, v3);
        map.connectRegion(v8, v9);
        map.connectRegion(v9, v3);
        map.connectRegion(v9, v4);
        map.connectRegion(v9, v10);
        map.connectRegion(v10, v4);
        map.connectRegion(v10, v5);
        map.connectRegion(v10, v11);
        map.connectRegion(v11, v5);
        map.connectRegion(v12, v6);
        map.connectRegion(v12, v7);
        map.connectRegion(v12, v13);
        map.connectRegion(v13, v7);
        map.connectRegion(v13, v8);
        map.connectRegion(v13, v14);
        map.connectRegion(v14, v8);
        map.connectRegion(v14, v9);
        map.connectRegion(v14, v15);
        map.connectRegion(v15, v9);
        map.connectRegion(v15, v10);
        map.connectRegion(v15, v11);
        map.connectRegion(v15, v16);
        map.connectRegion(v16, v11);
        map.connectRegion(v17, v12);
        map.connectRegion(v17, v18);
        map.connectRegion(v18, v12);
        map.connectRegion(v18, v13);
        map.connectRegion(v18, v19);
        map.connectRegion(v19, v13);
        map.connectRegion(v19, v14);
        map.connectRegion(v19, v20);
        map.connectRegion(v20, v14);
        map.connectRegion(v20, v21);
        map.connectRegion(v21, v14);
        map.connectRegion(v21, v15);
        map.connectRegion(v21, v22);
        map.connectRegion(v22, v15);
        map.connectRegion(v22, v16);
        map.connectRegion(v22, v23);
        map.connectRegion(v23, v21);

        assert(map.isConnected());

        map.exportMap("2player.map");
        map.exportMapGraphViz("2player.viz");
    }

}

