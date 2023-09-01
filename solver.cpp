#include <iostream>
using namespace std;

int main(){
    system("cls");

//change number here
    int sudoku[9][9] = {
        // {9,0,0, 6,0,0, 0,0,0},
        // {0,8,0, 0,3,2, 1,5,9},
        // {0,0,0, 9,1,7, 8,0,6},

        // {0,7,0, 0,6,0, 0,2,1},
        // {0,6,0, 3,0,4, 9,0,0},
        // {5,3,0, 0,2,0, 6,0,7},

        // {0,0,1, 7,0,3, 0,0,2},
        // {0,0,6, 5,0,1, 4,0,0},
        // {3,4,0, 2,0,0, 0,1,0}


        {6,1,3, 0,2,0, 5,4,0},
        {2,0,0, 0,4,6, 0,3,1},
        {0,0,0, 0,3,0, 6,7,2},

        {0,6,1, 0,0,0, 0,0,0},
        {0,7,0, 0,6,9, 0,1,5},
        {4,0,9, 5,8,0, 0,6,0},

        {0,0,0, 8,1,2, 3,0,0},
        {0,9,6, 0,0,0, 2,8,0},
        {0,3,0, 0,0,0, 0,5,7}


        // {0,0,4, 0,3,8, 0,0,9},
        // {0,0,8, 0,0,0, 0,0,4},
        // {0,0,0, 0,7,0, 0,0,0},

        // {0,2,0, 0,0,0, 5,6,0},
        // {0,0,0, 0,0,0, 3,4,0},
        // {6,8,0, 2,0,0, 0,0,0},

        // {0,0,0, 0,4,0, 0,2,0},
        // {3,0,9, 7,2,0, 8,0,1},
        // {0,0,0, 8,0,1, 0,0,0}


        // {0,0,0, 0,0,0, 0,0,0},
        // {0,0,0, 0,0,0, 0,0,0},
        // {0,0,0, 0,0,0, 0,0,0},

        // {0,0,0, 0,0,0, 0,0,0},
        // {0,0,0, 0,0,0, 0,0,0},
        // {0,0,0, 0,0,0, 0,0,0},

        // {0,0,0, 0,0,0, 0,0,0},
        // {0,0,0, 0,0,0, 0,0,0},
        // {0,0,0, 0,0,0, 0,0,0}
    };

    int zone[2];
    int solution;
    
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            // cout << "| ";            

            zone[0] = i/3;
            zone[1] = j/3;

            int possibleCounter = 0;
            bool possible[9] = {true,true,true,true,true,true,true,true,true};


            if (sudoku[i][j] == 0){
                for (int a = 0; a < 9; a++){
                    for (int b = 0; b < 9; b++){  
                        if (sudoku[i][a] == b+1){
                            possible[b] = false;
                        }
                        else if (sudoku[a][j] == b+1){
                            possible[b] = false;
                        }
                    }
                }

                int counter = 0;
                for (int a = 3 * zone[0]; a < (3*zone[0]) + 3; a++){
                    for (int b = 3 * zone[1]; b < (3*zone[1]) + 3; b++){ 
                        for (int c = 0; c < 9; c++){
                            if(sudoku[a][b] == c+1){
                                possible[c] = false;
                            }
                        }
                    }
                } 

                for (int a = 0; a < 9; a++)
                {
                    if(possible[a]){
                        possibleCounter++;
                        solution = a+1;
                    } 
                    if (possibleCounter == 2) break;                    
                }

                if(possibleCounter == 1){
                    sudoku[i][j] = solution;
                    i = 0;
                    j = 0;

                    system("cls");
                    cout << "\n\n|-----------|-----------|-----------|\n";
                    for (int a = 0; a < 9; a++){
                        for (int b = 0; b < 9; b++){  
                            cout << "| ";
                            cout << sudoku[a][b] << " ";
                        }
                        if(a % 3 == 2) cout << "|\n|===========|===========|===========|\n";
                        else cout << "|\n|-----------|-----------|-----------|\n";
                    }
                }
                else{
                    for (int a = 0; a < 9; a++){
                        if(possible[a]){
                            int valid = 0;
                            int filled;
                            bool valid2;
                            for (int b = 3 * zone[0]; b < (3*zone[0]) + 3; b++){
                                filled = 0;
                                valid2 = false;
                                if(b != i){
                                    for (int c = 0; c < 9; c++){
                                        if(sudoku[b][c] == a+1){
                                            valid++;
                                            valid2 = true;
                                        } 
                                    }
                                    if(!valid2){
                                        for (int c = 3 * zone[1]; c < (3*zone[1]) + 3; c++){
                                            if(sudoku[b][c] != 0) filled++;
                                        }
                                        if(filled == 3) valid++;
                                    }
                                }
                            }
                            for (int b = 3 * zone[1]; b < (3*zone[1]) + 3; b++){
                                filled = 0;
                                valid2 = false;
                                if(b != j){
                                    for (int c = 0; c < 9; c++){
                                        if(sudoku[c][b] == a+1){
                                            valid++;
                                            valid2 = true;
                                        } 
                                    }
                                    if(!valid2){
                                        for (int c = 3 * zone[0]; c < (3*zone[0]) + 3; c++){
                                            if(sudoku[c][b] != 0) filled++;
                                        }
                                        if(filled == 3) valid++;
                                    }
                                }
                            }
                            if(valid==4 && sudoku[i][j] == 0){
                                sudoku[i][j] = a+1;
                                i = 0;
                                j = 0;

                                system("cls");
                                cout << "\n\n|-----------|-----------|-----------|\n";
                                for (int a = 0; a < 9; a++){
                                    for (int b = 0; b < 9; b++){  
                                        cout << "| ";
                                        cout << sudoku[a][b] << " ";
                                    }
                                    if(a % 3 == 2) cout << "|\n|===========|===========|===========|\n";
                                    else cout << "|\n|-----------|-----------|-----------|\n";
                                }
                            }
                        }
                    } 
                }  
            }
        }
    }

    system("cls");
    cout << "|-----------|-----------|-----------|\n";
    for (int a = 0; a < 9; a++){
        for (int b = 0; b < 9; b++){  
            cout << "| ";
            cout << sudoku[a][b] << " ";
        }
        if(a % 3 == 2) cout << "|\n|===========|===========|===========|\n";
        else cout << "|\n|-----------|-----------|-----------|\n";
    }

}