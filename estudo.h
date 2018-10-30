void registrarDinamica(int atual,int ultimo, int penultimo,int dinamicaNeuronios[2][16][4],float potencial[64], int contaQtd[64]){
    if((((*Iz).disparos[entradas] >= limiar_pulsos)&&(atual == penultimo))){ // True Positive

        if(atual == 0){
            if(ultimo == 0){ // 0 0 0
                dinamicaNeuronios[0][0][0]++;
                potencial[0] += (*Iz).n[4].v;
                contaQtd[0] += 1;
            }
            else if(ultimo == 1){ // 0 1 0
                dinamicaNeuronios[0][0][1]++;
                potencial[1] += (*Iz).n[4].v;
                contaQtd[1] += 1;
            }
            else if(ultimo == 2){ // 0 2 0
                dinamicaNeuronios[0][0][2]++;
                potencial[2] += (*Iz).n[4].v;
                contaQtd[2] += 1;
            }
            else if(ultimo == 3){ // 0 3 0
                dinamicaNeuronios[0][0][3]++;
                potencial[3] += (*Iz).n[4].v;
                contaQtd[3] += 1;
            }
        }
        else if(atual == 1){
            if(ultimo == 0){ // 1 0 1
                dinamicaNeuronios[0][5][0]++;
                potencial[20] += (*Iz).n[4].v;
                contaQtd[20] += 1;
            }
            else if(ultimo == 1){ // 1 1 1
                dinamicaNeuronios[0][5][1]++;
                potencial[21] += (*Iz).n[4].v;
                contaQtd[21] += 1;
            }
            else if(ultimo == 2){ // 1 2 1
                dinamicaNeuronios[0][5][2]++;
                potencial[22] += (*Iz).n[4].v;
                contaQtd[22] += 1;
            }
            else if(ultimo == 3){ // 1 3 1
                dinamicaNeuronios[0][5][3]++;
                potencial[23] += (*Iz).n[4].v;
                contaQtd[23] += 1;
            }
        }
        else if(atual == 2){
            if(ultimo == 0){ // 2 0 2
                dinamicaNeuronios[0][10][0]++;
                potencial[40] += (*Iz).n[4].v;
                contaQtd[40] += 1;
            }
            else if(ultimo == 1){ // 2 1 2
                dinamicaNeuronios[0][10][1]++;
                potencial[41] += (*Iz).n[4].v;
                contaQtd[41] += 1;
            }
            else if(ultimo == 2){ // 2 2 2
                dinamicaNeuronios[0][10][2]++;
                potencial[42] += (*Iz).n[4].v;
                contaQtd[42] += 1;
            }
            else if(ultimo == 3){ // 2 3 2
                dinamicaNeuronios[0][10][3]++;
                potencial[43] += (*Iz).n[4].v;
                contaQtd[43] += 1;
            }
        }
        else if(atual == 3){
            if(ultimo == 0){ // 3 0 3
                dinamicaNeuronios[0][15][0]++;
                potencial[60] += (*Iz).n[4].v;
                contaQtd[60] += 1;
            }
            else if(ultimo == 1){ // 3 1 3
                dinamicaNeuronios[0][15][1]++;
                potencial[61] += (*Iz).n[4].v;
                contaQtd[61] += 1;
            }
            else if(ultimo == 2){ // 3 2 3
                dinamicaNeuronios[0][15][2]++;
                potencial[62] += (*Iz).n[4].v;
                contaQtd[62] += 1;
            }
            else if(ultimo == 3){ // 3 3 3
                dinamicaNeuronios[0][15][3]++;
                potencial[63] += (*Iz).n[4].v;
                contaQtd[63] += 1;
            }
        }
    }
    if((((*Iz).disparos[entradas] < limiar_pulsos)&&(atual != penultimo))){ // True Negative

        if(atual == 0){
            if(penultimo == 1){
                if(ultimo == 0){ // 0 0 1
                    dinamicaNeuronios[0][1][0]++;
                    potencial[4] += (*Iz).n[4].v;
                    contaQtd[4] += 1;
                }
                else if(ultimo == 1){ // 0 1 1
                    dinamicaNeuronios[0][1][1]++;
                    potencial[5] += (*Iz).n[4].v;
                    contaQtd[5] += 1;
                }
                else if(ultimo == 2){ // 0 2 1
                    dinamicaNeuronios[0][1][2]++;
                    potencial[6] += (*Iz).n[4].v;
                    contaQtd[6] += 1;
                }
                else if(ultimo == 3){ // 0 3 1
                    dinamicaNeuronios[0][1][3]++;
                    potencial[7] += (*Iz).n[4].v;
                    contaQtd[7] += 1;
                }
            }
            else if(penultimo == 2){
                if(ultimo == 0){ // 0 0 2
                    dinamicaNeuronios[0][2][0]++;
                    potencial[8] += (*Iz).n[4].v;
                    contaQtd[8] += 1;
                }
                else if(ultimo == 1){ // 0 1 2
                    dinamicaNeuronios[0][2][1]++;
                    potencial[9] += (*Iz).n[4].v;
                    contaQtd[9] += 1;
                }
                else if(ultimo == 2){ // 0 2 2
                    dinamicaNeuronios[0][2][2]++;
                    potencial[10] += (*Iz).n[4].v;
                    contaQtd[10] += 1;
                }
                else if(ultimo == 3){ // 0 3 2
                    dinamicaNeuronios[0][2][3]++;
                    potencial[11] += (*Iz).n[4].v;
                    contaQtd[11] += 1;
                }
            }
            else if(penultimo == 3){
                if(ultimo == 0){ // 0 0 3
                    dinamicaNeuronios[0][3][0]++;
                    potencial[12] += (*Iz).n[4].v;
                    contaQtd[12] += 1;
                }
                else if(ultimo == 1){ // 0 1 3
                    dinamicaNeuronios[0][3][1]++;
                    potencial[13] += (*Iz).n[4].v;
                    contaQtd[13] += 1;
                }
                else if(ultimo == 2){ // 0 2 3
                    dinamicaNeuronios[0][3][2]++;
                    potencial[14] += (*Iz).n[4].v;
                    contaQtd[14] += 1;
                }
                else if(ultimo == 3){ // 0 3 3
                    dinamicaNeuronios[0][3][3]++;
                    potencial[15] += (*Iz).n[4].v;
                    contaQtd[15] += 1;
                }
            }
        }
        else if(atual == 1){
            if(penultimo == 0){
                if(ultimo == 0){ // 1 0 0
                    dinamicaNeuronios[0][4][0]++;
                    potencial[16] += (*Iz).n[4].v;
                    contaQtd[16] += 1;
                }
                else if(ultimo == 1){ // 1 1 0
                    dinamicaNeuronios[0][4][1]++;
                    potencial[17] += (*Iz).n[4].v;
                    contaQtd[17] += 1;
                }
                else if(ultimo == 2){ // 1 2 0
                    dinamicaNeuronios[0][4][2]++;
                    potencial[18] += (*Iz).n[4].v;
                    contaQtd[18] += 1;
                }
                else if(ultimo == 3){ // 1 3 0
                    dinamicaNeuronios[0][4][3]++;
                    potencial[19] += (*Iz).n[4].v;
                    contaQtd[19] += 1;
                }
            }
            else if(penultimo == 2){
                if(ultimo == 0){ // 1 0 2
                    dinamicaNeuronios[0][6][0]++;
                    potencial[24] += (*Iz).n[4].v;
                    contaQtd[24] += 1;
                }
                else if(ultimo == 1){ // 1 1 2
                    dinamicaNeuronios[0][6][1]++;
                    potencial[25] += (*Iz).n[4].v;
                    contaQtd[25] += 1;
                }
                else if(ultimo == 2){ // 1 2 2
                    dinamicaNeuronios[0][6][2]++;
                    potencial[26] += (*Iz).n[4].v;
                    contaQtd[26] += 1;
                }
                else if(ultimo == 3){ // 1 3 2
                    dinamicaNeuronios[0][6][3]++;
                    potencial[27] += (*Iz).n[4].v;
                    contaQtd[27] += 1;
                }
            }
            else if(penultimo == 3){
                if(ultimo == 0){ // 1 0 3
                    dinamicaNeuronios[0][7][0]++;
                    potencial[28] += (*Iz).n[4].v;
                    contaQtd[28] += 1;
                }
                else if(ultimo == 1){ // 1 1 3
                    dinamicaNeuronios[0][7][1]++;
                    potencial[29] += (*Iz).n[4].v;
                    contaQtd[29] += 1;
                }
                else if(ultimo == 2){ // 1 2 3 
                    dinamicaNeuronios[0][7][2]++;
                    potencial[30] += (*Iz).n[4].v;
                    contaQtd[30] += 1;
                }
                else if(ultimo == 3){ // 1 3 3
                    dinamicaNeuronios[0][7][3]++;
                    potencial[31] += (*Iz).n[4].v;
                    contaQtd[31] += 1;
                }
            }
        }
        else if(atual == 2){
            if(penultimo == 0){
                if(ultimo == 0){ // 2 0 0
                    dinamicaNeuronios[0][8][0]++;
                    potencial[32] += (*Iz).n[4].v;
                    contaQtd[32] += 1;
                }
                else if(ultimo == 1){ // 2 1 0
                    dinamicaNeuronios[0][8][1]++;
                    potencial[33] += (*Iz).n[4].v;
                    contaQtd[33] += 1;
                }
                else if(ultimo == 2){ // 2 2 0
                    dinamicaNeuronios[0][8][2]++;
                    potencial[34] += (*Iz).n[4].v;
                    contaQtd[34] += 1;
                }
                else if(ultimo == 3){ // 2 3 0
                    dinamicaNeuronios[0][8][3]++;
                    potencial[35] += (*Iz).n[4].v;
                    contaQtd[35] += 1;
                }
            }
            else if(penultimo == 1){
                if(ultimo == 0){ // 2 0 1
                    dinamicaNeuronios[0][9][0]++;
                    potencial[36] += (*Iz).n[4].v;
                    contaQtd[36] += 1;
                }
                else if(ultimo == 1){ // 2 1 1
                    dinamicaNeuronios[0][9][1]++;
                    potencial[37] += (*Iz).n[4].v;
                    contaQtd[37] += 1;
                }
                else if(ultimo == 2){ // 2 2 1
                    dinamicaNeuronios[0][9][2]++;
                    potencial[38] += (*Iz).n[4].v;
                    contaQtd[38] += 1;
                }
                else if(ultimo == 3){ // 2 3 1
                    dinamicaNeuronios[0][9][3]++;
                    potencial[39] += (*Iz).n[4].v;
                    contaQtd[39] += 1;
                }
            }
            else if(penultimo == 3){
                if(ultimo == 0){ // 2 0 3
                    dinamicaNeuronios[0][11][0]++;
                    potencial[44] += (*Iz).n[4].v;
                    contaQtd[44] += 1;
                }
                else if(ultimo == 1){ // 2 1 3
                    dinamicaNeuronios[0][11][1]++;
                    potencial[45] += (*Iz).n[4].v;
                    contaQtd[45] += 1;
                }
                else if(ultimo == 2){ // 2 2 3
                    dinamicaNeuronios[0][11][2]++;
                    potencial[46] += (*Iz).n[4].v;
                    contaQtd[46] += 1;
                }
                else if(ultimo == 3){ // 2 3 3
                    dinamicaNeuronios[0][11][3]++;
                    potencial[47] += (*Iz).n[4].v;
                    contaQtd[47] += 1;
                }
            }
        }
        else if(atual == 3){
            if(penultimo == 0){
                if(ultimo == 0){ // 3 0 0
                    dinamicaNeuronios[0][12][0]++;
                    potencial[48] += (*Iz).n[4].v;
                    contaQtd[48] += 1;
                }
                else if(ultimo == 1){ // 3 1 0
                    dinamicaNeuronios[0][12][1]++;
                    potencial[49] += (*Iz).n[4].v;
                    contaQtd[49] += 1;
                }
                else if(ultimo == 2){ // 3 2 0
                    dinamicaNeuronios[0][12][2]++;
                    potencial[50] += (*Iz).n[4].v;
                    contaQtd[50] += 1;
                }
                else if(ultimo == 3){ // 3 3 0
                    dinamicaNeuronios[0][12][3]++;
                    potencial[51] += (*Iz).n[4].v;
                    contaQtd[51] += 1;
                }
            }
            else if(penultimo == 1){
                if(ultimo == 0){ // 3 0 1
                    dinamicaNeuronios[0][13][0]++;
                    potencial[52] += (*Iz).n[4].v;
                    contaQtd[52] += 1;
                }
                else if(ultimo == 1){ // 3 1 1
                    dinamicaNeuronios[0][13][1]++;
                    potencial[53] += (*Iz).n[4].v;
                    contaQtd[53] += 1;
                }
                else if(ultimo == 2){ // 3 2 1
                    dinamicaNeuronios[0][13][2]++;
                    potencial[54] += (*Iz).n[4].v;
                    contaQtd[54] += 1;
                }
                else if(ultimo == 3){ // 3 3 1
                    dinamicaNeuronios[0][13][3]++;
                    potencial[55] += (*Iz).n[4].v;
                    contaQtd[55] += 1;
               }
            }
            else if(penultimo == 2){
                if(ultimo == 0){ // 3 0 2
                    dinamicaNeuronios[0][14][0]++;
                    potencial[56] += (*Iz).n[4].v;
                    contaQtd[56] += 1;
                }
                else if(ultimo == 1){ // 3 1 2
                    dinamicaNeuronios[0][14][1]++;
                    potencial[57] += (*Iz).n[4].v;
                    contaQtd[57] += 1;
                }
                else if(ultimo == 2){ // 3 2 2
                    dinamicaNeuronios[0][14][2]++;
                    potencial[58] += (*Iz).n[4].v;
                    contaQtd[58] += 1;
                }
                else if(ultimo == 3){ // 3 3 2
                    dinamicaNeuronios[0][14][3]++;
                    potencial[59] += (*Iz).n[4].v;
                    contaQtd[59] += 1;
                }
            }
        }
    }
    if((((*Iz).disparos[entradas] >= limiar_pulsos)&&(atual != penultimo))){ // False Positive

        if(atual == 0){
            if(penultimo == 1){
                if(ultimo == 0){ // 0 0 1
                    dinamicaNeuronios[1][1][0]++;
                    potencial[4] += (*Iz).n[4].v;
                    contaQtd[4] += 1;
                }
                else if(ultimo == 1){ // 0 1 1
                    dinamicaNeuronios[1][1][1]++;
                    potencial[5] += (*Iz).n[4].v;
                    contaQtd[5] += 1;
                }
                else if(ultimo == 2){ // 0 2 1
                    dinamicaNeuronios[1][1][2]++;
                    potencial[6] += (*Iz).n[4].v;
                    contaQtd[6] += 1;
                }
                else if(ultimo == 3){ // 0 3 1
                    dinamicaNeuronios[1][1][3]++;
                    potencial[7] += (*Iz).n[4].v;
                    contaQtd[7] += 1;
                }
            }
            else if(penultimo == 2){
                if(ultimo == 0){ // 0 0 2
                    dinamicaNeuronios[1][2][0]++;
                    potencial[8] += (*Iz).n[4].v;
                    contaQtd[8] += 1;
                }
                else if(ultimo == 1){ // 0 1 2
                    dinamicaNeuronios[1][2][1]++;
                    potencial[9] += (*Iz).n[4].v;
                    contaQtd[9] += 1;
                }
                else if(ultimo == 2){ // 0 2 2
                    dinamicaNeuronios[1][2][2]++;
                    potencial[10] += (*Iz).n[4].v;
                    contaQtd[10] += 1;
                }
                else if(ultimo == 3){ // 0 3 2
                    dinamicaNeuronios[1][2][3]++;
                    potencial[11] += (*Iz).n[4].v;
                    contaQtd[11] += 1;
                }
            }
            else if(penultimo == 3){
                if(ultimo == 0){ // 0 0 3
                    dinamicaNeuronios[1][3][0]++;
                    potencial[12] += (*Iz).n[4].v;
                    contaQtd[12] += 1;
                }
                else if(ultimo == 1){ // 0 1 3
                    dinamicaNeuronios[1][3][1]++;
                    potencial[13] += (*Iz).n[4].v;
                    contaQtd[13] += 1;
                }
                else if(ultimo == 2){ // 0 2 3
                    dinamicaNeuronios[1][3][2]++;
                    potencial[14] += (*Iz).n[4].v;
                    contaQtd[14] += 1;
                }
                else if(ultimo == 3){ // 0 3 3
                    dinamicaNeuronios[1][3][3]++;
                    potencial[15] += (*Iz).n[4].v;
                    contaQtd[15] += 1;
                }
            }
        }
        else if(atual == 1){
            if(penultimo == 0){
                if(ultimo == 0){ // 1 0 0
                    dinamicaNeuronios[1][4][0]++;
                    potencial[16] += (*Iz).n[4].v;
                    contaQtd[16] += 1;
                }
                else if(ultimo == 1){ // 1 1 0
                    dinamicaNeuronios[1][4][1]++;
                    potencial[17] += (*Iz).n[4].v;
                    contaQtd[17] += 1;
                }
                else if(ultimo == 2){ // 1 2 0
                    dinamicaNeuronios[1][4][2]++;
                    potencial[18] += (*Iz).n[4].v;
                    contaQtd[18] += 1;
                }
                else if(ultimo == 3){ // 1 3 0
                    dinamicaNeuronios[1][4][3]++;
                    potencial[19] += (*Iz).n[4].v;
                    contaQtd[19] += 1;
                }
            }
            else if(penultimo == 2){
                if(ultimo == 0){ // 1 0 2
                    dinamicaNeuronios[1][6][0]++;
                    potencial[24] += (*Iz).n[4].v;
                    contaQtd[24] += 1;
                }
                else if(ultimo == 1){ // 1 1 2
                    dinamicaNeuronios[1][6][1]++;
                    potencial[25] += (*Iz).n[4].v;
                    contaQtd[25] += 1;
                }
                else if(ultimo == 2){ // 1 2 2
                    dinamicaNeuronios[1][6][2]++;
                    potencial[26] += (*Iz).n[4].v;
                    contaQtd[26] += 1;
                }
                else if(ultimo == 3){ // 1 3 2
                    dinamicaNeuronios[1][6][3]++;
                    potencial[27] += (*Iz).n[4].v;
                    contaQtd[27] += 1;
                }
            }
            else if(penultimo == 3){
                if(ultimo == 0){ // 1 0 3
                    dinamicaNeuronios[1][7][0]++;
                    potencial[28] += (*Iz).n[4].v;
                    contaQtd[28] += 1;
                }
                else if(ultimo == 1){ // 1 1 3
                    dinamicaNeuronios[1][7][1]++;
                    potencial[29] += (*Iz).n[4].v;
                    contaQtd[29] += 1;
                }
                else if(ultimo == 2){ // 1 2 3 
                    dinamicaNeuronios[1][7][2]++;
                    potencial[30] += (*Iz).n[4].v;
                    contaQtd[30] += 1;
                }
                else if(ultimo == 3){ // 1 3 3
                    dinamicaNeuronios[1][7][3]++;
                    potencial[31] += (*Iz).n[4].v;
                    contaQtd[31] += 1;
                }
            }
        }
        else if(atual == 2){
            if(penultimo == 0){
                if(ultimo == 0){ // 2 0 0
                    dinamicaNeuronios[1][8][0]++;
                    potencial[32] += (*Iz).n[4].v;
                    contaQtd[32] += 1;
                }
                else if(ultimo == 1){ // 2 1 0
                    dinamicaNeuronios[1][8][1]++;
                    potencial[33] += (*Iz).n[4].v;
                    contaQtd[33] += 1;
                }
                else if(ultimo == 2){ // 2 2 0
                    dinamicaNeuronios[1][8][2]++;
                    potencial[34] += (*Iz).n[4].v;
                    contaQtd[34] += 1;
                }
                else if(ultimo == 3){ // 2 3 0
                    dinamicaNeuronios[1][8][3]++;
                    potencial[35] += (*Iz).n[4].v;
                    contaQtd[35] += 1;
                }
            }
            else if(penultimo == 1){
                if(ultimo == 0){ // 2 0 1
                    dinamicaNeuronios[1][9][0]++;
                    potencial[36] += (*Iz).n[4].v;
                    contaQtd[36] += 1;
                }
                else if(ultimo == 1){ // 2 1 1
                    dinamicaNeuronios[1][9][1]++;
                    potencial[37] += (*Iz).n[4].v;
                    contaQtd[37] += 1;
                }
                else if(ultimo == 2){ // 2 2 1
                    dinamicaNeuronios[1][9][2]++;
                    potencial[38] += (*Iz).n[4].v;
                    contaQtd[38] += 1;
                }
                else if(ultimo == 3){ // 2 3 1
                    dinamicaNeuronios[1][9][3]++;
                    potencial[39] += (*Iz).n[4].v;
                    contaQtd[39] += 1;
                }
            }
            else if(penultimo == 3){
                if(ultimo == 0){ // 2 0 3
                    dinamicaNeuronios[1][11][0]++;
                    potencial[44] += (*Iz).n[4].v;
                    contaQtd[44] += 1;
                }
                else if(ultimo == 1){ // 2 1 3
                    dinamicaNeuronios[1][11][1]++;
                    potencial[45] += (*Iz).n[4].v;
                    contaQtd[45] += 1;
                }
                else if(ultimo == 2){ // 2 2 3
                    dinamicaNeuronios[1][11][2]++;
                    potencial[46] += (*Iz).n[4].v;
                    contaQtd[46] += 1;
                }
                else if(ultimo == 3){ // 2 3 3
                    dinamicaNeuronios[1][11][3]++;
                    potencial[47] += (*Iz).n[4].v;
                    contaQtd[47] += 1;
                }
            }
        }
        else if(atual == 3){
            if(penultimo == 0){
                if(ultimo == 0){ // 3 0 0
                    dinamicaNeuronios[1][12][0]++;
                    potencial[48] += (*Iz).n[4].v;
                    contaQtd[48] += 1;
                }
                else if(ultimo == 1){ // 3 1 0
                    dinamicaNeuronios[1][12][1]++;
                    potencial[49] += (*Iz).n[4].v;
                    contaQtd[49] += 1;
                }
                else if(ultimo == 2){ // 3 2 0
                    dinamicaNeuronios[1][12][2]++;
                    potencial[50] += (*Iz).n[4].v;
                    contaQtd[50] += 1;
                }
                else if(ultimo == 3){ // 3 3 0
                    dinamicaNeuronios[1][12][3]++;
                    potencial[51] += (*Iz).n[4].v;
                    contaQtd[51] += 1;
                }
            }
            else if(penultimo == 1){
                if(ultimo == 0){ // 3 0 1
                    dinamicaNeuronios[1][13][0]++;
                    potencial[52] += (*Iz).n[4].v;
                    contaQtd[52] += 1;
                }
                else if(ultimo == 1){ // 3 1 1
                    dinamicaNeuronios[1][13][1]++;
                    potencial[53] += (*Iz).n[4].v;
                    contaQtd[53] += 1;
                }
                else if(ultimo == 2){ // 3 2 1
                    dinamicaNeuronios[1][13][2]++;
                    potencial[54] += (*Iz).n[4].v;
                    contaQtd[54] += 1;
                }
                else if(ultimo == 3){ // 3 3 1
                    dinamicaNeuronios[1][13][3]++;
                    potencial[55] += (*Iz).n[4].v;
                    contaQtd[55] += 1;
               }
            }
            else if(penultimo == 2){
                if(ultimo == 0){ // 3 0 2
                    dinamicaNeuronios[1][14][0]++;
                    potencial[56] += (*Iz).n[4].v;
                    contaQtd[56] += 1;
                }
                else if(ultimo == 1){ // 3 1 2
                    dinamicaNeuronios[1][14][1]++;
                    potencial[57] += (*Iz).n[4].v;
                    contaQtd[57] += 1;
                }
                else if(ultimo == 2){ // 3 2 2
                    dinamicaNeuronios[1][14][2]++;
                    potencial[58] += (*Iz).n[4].v;
                    contaQtd[58] += 1;
                }
                else if(ultimo == 3){ // 3 3 2
                    dinamicaNeuronios[1][14][3]++;
                    potencial[59] += (*Iz).n[4].v;
                    contaQtd[59] += 1;
                }
            }
        }
    }
    if(((*Iz).disparos[entradas] < limiar_pulsos)&&(atual == penultimo)){ // False Negative

        if(atual == 0){
            if(ultimo == 0){ // 0 0 0
                dinamicaNeuronios[1][0][0]++;
                potencial[0] += (*Iz).n[4].v;
                contaQtd[0] += 1;
            }
            else if(ultimo == 1){ // 0 1 0
                dinamicaNeuronios[1][0][1]++;
                potencial[1] += (*Iz).n[4].v;
                contaQtd[1] += 1;
            }
            else if(ultimo == 2){ // 0 2 0
                dinamicaNeuronios[1][0][2]++;
                potencial[2] += (*Iz).n[4].v;
                contaQtd[2] += 1;
            }
            else if(ultimo == 3){ // 0 3 0
                dinamicaNeuronios[1][0][3]++;
                potencial[3] += (*Iz).n[4].v;
                contaQtd[3] += 1;
            }
        }
        else if(atual == 1){
            if(ultimo == 0){ // 1 0 1
                dinamicaNeuronios[1][5][0]++;
                potencial[20] += (*Iz).n[4].v;
                contaQtd[20] += 1;
            }
            else if(ultimo == 1){ // 1 1 1
                dinamicaNeuronios[1][5][1]++;
                potencial[21] += (*Iz).n[4].v;
                contaQtd[21] += 1;
            }
            else if(ultimo == 2){ // 1 2 1
                dinamicaNeuronios[1][5][2]++;
                potencial[22] += (*Iz).n[4].v;
                contaQtd[22] += 1;
            }
            else if(ultimo == 3){ // 1 3 1
                dinamicaNeuronios[1][5][3]++;
                potencial[23] += (*Iz).n[4].v;
                contaQtd[23] += 1;
            }
        }
        else if(atual == 2){
            if(ultimo == 0){ // 2 0 2
                dinamicaNeuronios[1][10][0]++;
                potencial[40] += (*Iz).n[4].v;
                contaQtd[40] += 1;
            }
            else if(ultimo == 1){ // 2 1 2
                dinamicaNeuronios[1][10][1]++;
                potencial[41] += (*Iz).n[4].v;
                contaQtd[41] += 1;
            }
            else if(ultimo == 2){ // 2 2 2
                dinamicaNeuronios[1][10][2]++;
                potencial[42] += (*Iz).n[4].v;
                contaQtd[42] += 1;
            }
            else if(ultimo == 3){ // 2 3 2
                dinamicaNeuronios[1][10][3]++;
                potencial[43] += (*Iz).n[4].v;
                contaQtd[43] += 1;
            }
        }
        else if(atual == 3){
            if(ultimo == 0){ // 3 0 3
                dinamicaNeuronios[1][15][0]++;
                potencial[60] += (*Iz).n[4].v;
                contaQtd[60] += 1;
            }
            else if(ultimo == 1){ // 3 1 3
                dinamicaNeuronios[1][15][1]++;
                potencial[61] += (*Iz).n[4].v;
                contaQtd[61] += 1;
            }
            else if(ultimo == 2){ // 3 2 3
                dinamicaNeuronios[1][15][2]++;
                potencial[62] += (*Iz).n[4].v;
                contaQtd[62] += 1;
            }
            else if(ultimo == 3){ // 3 3 3
                dinamicaNeuronios[1][15][3]++;
                potencial[63] += (*Iz).n[4].v;
                contaQtd[63] += 1;
            }
        }
    }
}
