
#include "../Map.hpp"


int main(int argc, char** argv)
{

    // 2 Player
    {
        Map map(2, 10);

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


    // 3 Player
    {
        Map map(3, 10);

        RegionNode regions[] = {
            /*0*/  RegionNode(), // index offset
            /*1*/  RegionNode(RegionType::SEA,      MapToken::NONE,     {RegionFeature::NONE},   false),
            /*2*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::MINE},   false),
            /*3*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::NONE},   false),
            /*4*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   false),
            /*5*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::CAVERN}, false),
            /*6*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::NONE},   true),
            /*7*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::MINE},   false),
            /*8*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, true),
            /*9*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::NONE},   false),
            /*10*/ RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, true),
            /*11*/ RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::MINE},   false),
            /*12*/ RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   true),
            /*13*/ RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::MINE, RegionFeature::CAVERN}, false),
            /*14*/ RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::NONE},   true),
            /*15*/ RegionNode(RegionType::SEA,      MapToken::NONE,     {RegionFeature::NONE},   false),
            /*16*/ RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::CAVERN}, false),
            /*17*/ RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, false),
            /*18*/ RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::NONE},   false),
            /*19*/ RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, false),
            /*20*/ RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::CAVERN}, true),
            /*21*/ RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::NONE},   false),
            /*22*/ RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, true),
            /*23*/ RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   true),
            /*24*/ RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::NONE},   false),
            /*25*/ RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::NONE},   false),
            /*26*/ RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::NONE},   false),
            /*27*/ RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::NONE},   false),
            /*28*/ RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::MINE},   true),
            /*29*/ RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::CAVERN}, true),
            /*30*/ RegionNode(RegionType::SEA,      MapToken::NONE,     {RegionFeature::NONE},   false),
        };


        Vertex v[31];
        for (int i = 1; i < 31; i++)
        {
            v[i] = map.addRegion(regions[i]);
        }

        map.connectRegion(v[1], v[2]);
        map.connectRegion(v[2], v[3]);
        map.connectRegion(v[3], v[4]);
        map.connectRegion(v[4], v[5]);
        map.connectRegion(v[5], v[6]);
        map.connectRegion(v[6], v[7]);

        map.connectRegion(v[1],  v[8]);
        map.connectRegion(v[8],  v[9]);
        map.connectRegion(v[9],  v[10]);
        map.connectRegion(v[10], v[11]);
        map.connectRegion(v[11], v[12]);
        map.connectRegion(v[12], v[7]);
        map.connectRegion(v[8],  v[2]);
        map.connectRegion(v[9],  v[2]);
        map.connectRegion(v[9],  v[3]);
        map.connectRegion(v[10], v[3]);
        map.connectRegion(v[10], v[4]);
        map.connectRegion(v[11], v[4]);
        map.connectRegion(v[11], v[5]);
        map.connectRegion(v[12], v[5]);
        map.connectRegion(v[12], v[6]);

        map.connectRegion(v[1],  v[13]);
        map.connectRegion(v[13], v[14]);
        map.connectRegion(v[14], v[15]);
        map.connectRegion(v[15], v[16]);
        map.connectRegion(v[16], v[17]);
        map.connectRegion(v[17], v[18]);
        map.connectRegion(v[13], v[8]);
        map.connectRegion(v[13], v[9]);
        map.connectRegion(v[14], v[9]);
        map.connectRegion(v[14], v[10]);
        map.connectRegion(v[15], v[10]);
        map.connectRegion(v[15], v[11]);
        map.connectRegion(v[16], v[11]);
        map.connectRegion(v[16], v[12]);
        map.connectRegion(v[17], v[12]);
        map.connectRegion(v[17], v[7]);
        map.connectRegion(v[18], v[7]);

        map.connectRegion(v[19], v[20]);
        map.connectRegion(v[20], v[21]);
        map.connectRegion(v[21], v[22]);
        map.connectRegion(v[22], v[23]);
        map.connectRegion(v[19], v[13]);
        map.connectRegion(v[19], v[14]);
        map.connectRegion(v[20], v[14]);
        map.connectRegion(v[20], v[15]);
        map.connectRegion(v[21], v[15]);
        map.connectRegion(v[22], v[15]);
        map.connectRegion(v[22], v[16]);
        map.connectRegion(v[23], v[16]);
        map.connectRegion(v[23], v[17]);

        map.connectRegion(v[24], v[25]);
        map.connectRegion(v[25], v[26]);
        map.connectRegion(v[26], v[27]);
        map.connectRegion(v[27], v[28]);
        map.connectRegion(v[28], v[29]);
        map.connectRegion(v[29], v[30]);
        map.connectRegion(v[24], v[19]);
        map.connectRegion(v[25], v[19]);
        map.connectRegion(v[25], v[20]);
        map.connectRegion(v[26], v[20]);
        map.connectRegion(v[26], v[21]);
        map.connectRegion(v[27], v[21]);
        map.connectRegion(v[27], v[22]);
        map.connectRegion(v[28], v[22]);
        map.connectRegion(v[28], v[23]);
        map.connectRegion(v[29], v[23]);
        map.connectRegion(v[29], v[17]);
        map.connectRegion(v[29], v[18]);
        map.connectRegion(v[28], v[30]);

        assert(map.isConnected());

        map.exportMap("3player.map");
        map.exportMapGraphViz("3player.viz");
    }


    { // 4 player

        Map map(4, 9);

        RegionNode regions[] = {
                /*0*/   RegionNode(), // index offset
                /*1*/   RegionNode(RegionType::SEA,      MapToken::NONE,     {RegionFeature::NONE},   false),
                /*2*/   RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   false),
                /*3*/   RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::CAVERN}, true),
                /*4*/   RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::NONE},   true),
                /*5*/   RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, false),
                /*6*/   RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::CAVERN}, false),
                /*7*/   RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, true),
                /*8*/   RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::MINE},   true),
                /*9*/   RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::CAVERN}, true),
                /*10*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   false),
                /*11*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::MINE},   false),
                /*12*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, true),
                /*13*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::NONE},   false),
                /*14*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::NONE},   false),
                /*15*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::NONE},   true),
                /*16*/  RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, false),
                /*17*/  RegionNode(RegionType::SEA,      MapToken::NONE,     {RegionFeature::NONE},   false),
                /*18*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::MINE},   false),
                /*19*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   false),
                /*20*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::NONE},   false),
                /*21*/  RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::NONE},   false),
                /*22*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::MINE, RegionFeature::CAVERN}, false),
                /*23*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::NONE},   false),
                /*24*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   true),
                /*25*/  RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::NONE},   true),
                /*26*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::CAVERN}, true),
                /*27*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::MINE},   true),
                /*28*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, true),
                /*29*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   false),
                /*30*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::NONE},   false),
                /*31*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::CAVERN}, true),
                /*32*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, true),
                /*33*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::MINE},   false),
                /*34*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::CAVERN}, false),
                /*35*/  RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, false),
                /*36*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::NONE},   false),
                /*37*/  RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::MINE},   false),
                /*38*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   false),
                /*39*/  RegionNode(RegionType::SEA,      MapToken::NONE,     {RegionFeature::NONE},   false),
        };


        Vertex v[40];
        for (int i = 1; i < 40; i++)
        {
            v[i] = map.addRegion(regions[i]);
        }


        map.connectRegion(v[1], v[2]); //1
        map.connectRegion(v[1], v[3]);
        map.connectRegion(v[1], v[7]);
        map.connectRegion(v[1], v[8]);
        map.connectRegion(v[1], v[9]);
        map.connectRegion(v[1], v[14]);
        map.connectRegion(v[1], v[20]);

        map.connectRegion(v[2], v[7]); //2

        map.connectRegion(v[3], v[4]); //3
        map.connectRegion(v[3], v[8]);

        map.connectRegion(v[4], v[5]); //4
        map.connectRegion(v[4], v[8]);
        map.connectRegion(v[4], v[10]);
        map.connectRegion(v[4], v[11]);

        map.connectRegion(v[5], v[6]); //5
        map.connectRegion(v[5], v[11]);

        map.connectRegion(v[6], v[11]); //6
        map.connectRegion(v[6], v[12]);
        map.connectRegion(v[6], v[13]);

        map.connectRegion(v[7], v[9]); //7
        map.connectRegion(v[7], v[11]);
        map.connectRegion(v[7], v[14]);

        map.connectRegion(v[8], v[9]); //8

        map.connectRegion(v[9], v[10]); //9
        map.connectRegion(v[9], v[15]);

        map.connectRegion(v[10], v[11]); //10
        map.connectRegion(v[10], v[15]);
        map.connectRegion(v[10], v[16]);
        map.connectRegion(v[10], v[17]);

        map.connectRegion(v[11], v[12]); //11
        map.connectRegion(v[11], v[17]);

        map.connectRegion(v[12], v[13]); //12
        map.connectRegion(v[12], v[17]);
        map.connectRegion(v[12], v[18]);

        map.connectRegion(v[13], v[18]); //13
        map.connectRegion(v[13], v[19]);


        map.connectRegion(v[14], v[15]); //14
        map.connectRegion(v[14], v[20]);
        map.connectRegion(v[14], v[21]);

        map.connectRegion(v[15], v[16]); //15
        map.connectRegion(v[15], v[21]);
        map.connectRegion(v[15], v[22]);

        map.connectRegion(v[16], v[17]); //16
        map.connectRegion(v[16], v[22]);

        map.connectRegion(v[17], v[18]); //17
        map.connectRegion(v[17], v[22]);
        map.connectRegion(v[17], v[23]);
        map.connectRegion(v[17], v[24]);

        map.connectRegion(v[18], v[19]); //18
        map.connectRegion(v[18], v[24]);
        map.connectRegion(v[18], v[25]);

        map.connectRegion(v[19], v[25]); //19
        map.connectRegion(v[19], v[26]);

        map.connectRegion(v[20], v[21]); //20
        map.connectRegion(v[20], v[27]);

        map.connectRegion(v[21], v[22]); //21
        map.connectRegion(v[21], v[27]);
        map.connectRegion(v[21], v[28]);

        map.connectRegion(v[22], v[23]); //22
        map.connectRegion(v[22], v[28]);

        map.connectRegion(v[23], v[24]); //23
        map.connectRegion(v[23], v[28]);
        map.connectRegion(v[23], v[31]);

        map.connectRegion(v[24], v[25]); //24
        map.connectRegion(v[24], v[31]);
        map.connectRegion(v[24], v[32]);
        map.connectRegion(v[24], v[33]);
        map.connectRegion(v[24], v[34]);

        map.connectRegion(v[25], v[26]); //25
        map.connectRegion(v[25], v[35]);

        map.connectRegion(v[26], v[35]); //26

        map.connectRegion(v[27], v[28]); //27
        map.connectRegion(v[27], v[29]);

        map.connectRegion(v[28], v[29]); //28
        map.connectRegion(v[28], v[30]);
        map.connectRegion(v[28], v[31]);

        map.connectRegion(v[29], v[30]); //29

        map.connectRegion(v[30], v[31]); //30
        map.connectRegion(v[30], v[37]);

        map.connectRegion(v[31], v[32]); //31
        map.connectRegion(v[31], v[37]);
        map.connectRegion(v[31], v[38]);

        map.connectRegion(v[32], v[33]); //32
        map.connectRegion(v[32], v[38]);

        map.connectRegion(v[33], v[34]); //33
        map.connectRegion(v[33], v[36]);

        map.connectRegion(v[34], v[35]); //34
        map.connectRegion(v[34], v[25]);
        map.connectRegion(v[34], v[36]);

        map.connectRegion(v[35], v[36]); //35
        map.connectRegion(v[35], v[39]);

        map.connectRegion(v[36], v[39]);
        map.connectRegion(v[37], v[38]); //37
        map.connectRegion(v[38], v[33]); //38

        assert(map.isConnected());

        map.exportMap("4player.map");
        map.exportMapGraphViz("4player.viz");
    }


    { //5 player
        Map map(5, 8);

        RegionNode regions[] = {
                /*0*/   RegionNode(), // index offset
                /*1*/   RegionNode(RegionType::SEA,      MapToken::NONE,     {RegionFeature::NONE},   false),
                /*2*/   RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::NONE},   false),
                /*3*/   RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, false),
                /*4*/   RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::CAVERN}, false),
                /*5*/   RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, false),
                /*6*/   RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::CAVERN}, true),
                /*7*/   RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::NONE},   false),
                /*8*/   RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::MINE},   true),
                /*9*/   RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::NONE},   false),
                /*10*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::MINE},   false),
                /*11*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   false),
                /*12*/  RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::NONE},   true),
                /*13*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::CAVERN}, true),
                /*14*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::NONE},   false),
                /*15*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::CAVERN}, true),
                /*16*/  RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::MINE},   false),
                /*17*/  RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::NONE},   true),
                /*18*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, false),
                /*19*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::NONE},   true),
                /*20*/  RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, false),
                /*21*/  RegionNode(RegionType::SEA,      MapToken::NONE,     {RegionFeature::NONE},   false),
                /*22*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::NONE},   false),
                /*23*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::MAGIC_SOURCE}, false),
                /*24*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   true),
                /*25*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::CAVERN, RegionFeature::MINE}, false),
                /*26*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::MINE},   true),
                /*27*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   false),
                /*28*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::MINE},   false),
                /*29*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::NONE},   false),
                /*30*/  RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::NONE},   true),
                /*31*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::NONE},   true),
                /*32*/  RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::NONE},   false),
                /*33*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::CAVERN}, true),
                /*34*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::CAVERN}, true),
                /*35*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::NONE},   true),
                /*36*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::NONE},   false),
                /*37*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::CAVERN}, true),
                /*38*/  RegionNode(RegionType::FARM,     MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, false),
                /*39*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::MINE},   false),
                /*40*/  RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, true),
                /*41*/  RegionNode(RegionType::MARSH,    MapToken::NONE,     {RegionFeature::MINE},   false),
                /*42*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::MAGIC_SOURCE}, true),
                /*43*/  RegionNode(RegionType::HILL,     MapToken::NONE,     {RegionFeature::MINE},   false),
                /*44*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::MAGIC_SOURCE}, false),
                /*45*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::NONE},   false),
                /*46*/  RegionNode(RegionType::MOUNTAIN, MapToken::MOUNTAIN, {RegionFeature::NONE},   false),
                /*47*/  RegionNode(RegionType::FOREST,   MapToken::NONE,     {RegionFeature::CAVERN}, false),
                /*48*/  RegionNode(RegionType::SEA,      MapToken::NONE,     {RegionFeature::NONE},   false),
        };

        Vertex v[49];
        for (int i = 1; i < 49; i++)
        {
            v[i] = map.addRegion(regions[i]);
        }

        map.connectRegion(v[1], v[2]); //1
        map.connectRegion(v[1], v[7]);
        map.connectRegion(v[1], v[12]);
        map.connectRegion(v[1], v[17]);
        map.connectRegion(v[1], v[18]);
        map.connectRegion(v[1], v[24]);
        map.connectRegion(v[1], v[28]);
        map.connectRegion(v[1], v[29]);

        map.connectRegion(v[2], v[3]);
        map.connectRegion(v[2], v[7]);

        map.connectRegion(v[3], v[4]);
        map.connectRegion(v[3], v[7]);
        map.connectRegion(v[3], v[8]);

        map.connectRegion(v[4], v[5]);
        map.connectRegion(v[4], v[8]);
        map.connectRegion(v[4], v[9]);

        map.connectRegion(v[5], v[6]);
        map.connectRegion(v[5], v[9]);
        map.connectRegion(v[5], v[10]);

        map.connectRegion(v[6], v[10]);
        map.connectRegion(v[6], v[11]);

        map.connectRegion(v[7], v[8]);
        map.connectRegion(v[7], v[12]);

        map.connectRegion(v[8], v[9]);
        map.connectRegion(v[8], v[12]);
        map.connectRegion(v[8], v[13]);

        map.connectRegion(v[9], v[10]);
        map.connectRegion(v[9], v[13]);
        map.connectRegion(v[9], v[14]);

        map.connectRegion(v[10], v[11]);
        map.connectRegion(v[10], v[14]);
        map.connectRegion(v[10], v[15]);

        map.connectRegion(v[11], v[15]);
        map.connectRegion(v[11], v[16]);

        map.connectRegion(v[12], v[13]);
        map.connectRegion(v[12], v[18]);
        map.connectRegion(v[12], v[19]);

        map.connectRegion(v[13], v[14]);
        map.connectRegion(v[13], v[19]);
        map.connectRegion(v[13], v[20]);
        map.connectRegion(v[13], v[21]);

        map.connectRegion(v[14], v[15]);
        map.connectRegion(v[14], v[21]);
        map.connectRegion(v[14], v[22]);

        map.connectRegion(v[15], v[16]);
        map.connectRegion(v[15], v[22]);
        map.connectRegion(v[15], v[23]);

        map.connectRegion(v[16], v[23]);
        map.connectRegion(v[17], v[18]);

        map.connectRegion(v[18], v[19]);
        map.connectRegion(v[18], v[24]);

        map.connectRegion(v[19], v[20]);
        map.connectRegion(v[19], v[24]);
        map.connectRegion(v[19], v[25]);

        map.connectRegion(v[20], v[21]);
        map.connectRegion(v[20], v[25]);

        map.connectRegion(v[21], v[22]);
        map.connectRegion(v[21], v[25]);
        map.connectRegion(v[21], v[26]);
        map.connectRegion(v[21], v[30]);
        map.connectRegion(v[21], v[31]);
        map.connectRegion(v[21], v[37]);
        map.connectRegion(v[21], v[38]);

        map.connectRegion(v[22], v[23]);
        map.connectRegion(v[22], v[26]);

        map.connectRegion(v[23], v[26]);
        map.connectRegion(v[23], v[27]);

        map.connectRegion(v[24], v[25]);
        map.connectRegion(v[24], v[29]);
        map.connectRegion(v[24], v[30]);

        map.connectRegion(v[25], v[30]);

        map.connectRegion(v[26], v[27]);
        map.connectRegion(v[26], v[31]);
        map.connectRegion(v[26], v[32]);

        map.connectRegion(v[27], v[32]);
        map.connectRegion(v[27], v[33]);

        map.connectRegion(v[28], v[29]);
        map.connectRegion(v[28], v[34]);

        map.connectRegion(v[29], v[30]);
        map.connectRegion(v[29], v[34]);
        map.connectRegion(v[29], v[35]);

        map.connectRegion(v[30], v[35]);
        map.connectRegion(v[30], v[36]);
        map.connectRegion(v[30], v[37]);

        map.connectRegion(v[31], v[32]);
        map.connectRegion(v[31], v[38]);
        map.connectRegion(v[31], v[39]);

        map.connectRegion(v[32], v[33]);
        map.connectRegion(v[32], v[39]);
        map.connectRegion(v[32], v[40]);

        map.connectRegion(v[33], v[40]);

        map.connectRegion(v[34], v[35]);
        map.connectRegion(v[34], v[41]);

        map.connectRegion(v[35], v[36]);
        map.connectRegion(v[35], v[41]);
        map.connectRegion(v[35], v[42]);

        map.connectRegion(v[36], v[37]);
        map.connectRegion(v[36], v[42]);
        map.connectRegion(v[36], v[43]);

        map.connectRegion(v[37], v[38]);
        map.connectRegion(v[37], v[43]);
        map.connectRegion(v[37], v[44]);
        map.connectRegion(v[37], v[45]);

        map.connectRegion(v[38], v[39]);
        map.connectRegion(v[38], v[45]);
        map.connectRegion(v[38], v[46]);

        map.connectRegion(v[39], v[40]);
        map.connectRegion(v[39], v[46]);
        map.connectRegion(v[39], v[47]);

        map.connectRegion(v[40], v[47]);
        map.connectRegion(v[40], v[48]);

        map.connectRegion(v[41], v[42]);
        map.connectRegion(v[42], v[43]);
        map.connectRegion(v[43], v[44]);

        map.connectRegion(v[44], v[45]);
        map.connectRegion(v[44], v[46]);

        map.connectRegion(v[45], v[46]);
        map.connectRegion(v[46], v[47]);
        map.connectRegion(v[47], v[48]);

        assert(map.isConnected());

        map.exportMap("5player.map");
        map.exportMapGraphViz("5player.viz");
    }

}

