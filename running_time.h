
	/* 
	 * File:   bitset_size.h
	 * Author: addy
	 *
	 * Created on July 22, 2012, 2:38 PM
	 */                                                

//OLD-Pillai2
    // BITSET_SIZE 49 ~ 20mp  (d=3) - BITSET_SIZE 48 ~ 33mp  (d=3)
    // BITSET_SIZE 45 ~ 5s    (d=3)
    // BITSET_SIZE 25 ~ 200ms (d=2)
    // BITSET_SIZE 17 ~ 200ms (d=1)
        //n = 17;
        //d = 1;
            //Average node computing time: 11 microsec.
            //Average node apply computing time: 5 microsec.
            //Average node backtrack computing time: 2 microsec.
            //Average node computing: 18 piece
            //Average node apply computing time: 12 piece.
            //Average node backtrack computing time: 6 piece.
        //n = 25;
        //d = 2;
            //Average node computing time: 10 microsec.
            //Average node apply computing time: 7 microsec.
            //Average node backtrack computing time: 3 microsec.
            //Average node computing: 1299 piece
            //Average node apply computing time: 654 piece.
            //Average node backtrack computing time: 645 piece.
        //n = 45;
        //d = 3;
            //Average node computing time: 14 microsec.
            //Average node apply computing time: 14 microsec.
            //Average node backtrack computing time: 6 microsec.
            //Average node computing: 288801 piece
            //Average node apply computing time: 144400 piece.
            //Average node backtrack computing time: 144401 piece.
        //n = 48;
        //d = 3;
            //Average node computing time: 14 microsec.
            //Average node apply computing time: 14 microsec.
            //Average node backtrack computing time: 6 microsec.
            //Average node computing: 1582669 piece
            //Average node apply computing time: 791334 piece.
            //Average node backtrack computing time: 791335 piece.
        //n = 49;
        //d = 3;
            //Average node computing time: 15 microsec.
            //Average node apply computing time: 15 microsec.
            //Average node backtrack computing time: 6 microsec.
            //Average node computing: 980173 piece
            //Average node apply computing time: 490094 piece.
            //Average node backtrack computing time: 490079 piece.




//NEW-Pillai3
    // BITSET_SIZE 49 ~ ?     (d=3) - BITSET_SIZE 48 ~ 33mp  (d=3)
    // BITSET_SIZE 25 ~ 750ms (d=2)
    // BITSET_SIZE 17 ~ 211ms (d=1)

//NEW-Pillai4
    // BITSET_SIZE 49 ~ 3m    (d=3) - BITSET_SIZE 48 ~ 33mp  (d=3)
    // BITSET_SIZE 45 ~ 50s   (d=3) 
    // BITSET_SIZE 25 ~ 180ms (d=2)
    // BITSET_SIZE 17 ~ 150ms (d=1)

//NEW-Pillai5
    // BITSET_SIZE 49 ~ 3m    (d=3) - BITSET_SIZE 48 ~ 33mp  (d=3)
    // BITSET_SIZE 45 ~ 50s   (d=3) 
    // BITSET_SIZE 25 ~ 180ms (d=2)
    // BITSET_SIZE 17 ~ 150ms (d=1)
            //n = 17;
            //d = 1;
                //AI Solution: 
                //Average node computing time: 12 microsec.
                //Average node apply computing time: 5 microsec.
                //Average node backtrack computing time: 2 microsec.
                //Average node computing : 18 piece
                //Average node apply computing time : 12 piece.
                //Average node backtrack computing time : 6 piece.
                //RUN SUCCESSFUL (total time: 309ms)
            //n = 25;
            //d = 2;
                //Average node computing time: 9 microsec.
                //Average node apply computing time: 7 microsec.
                //Average node backtrack computing time: 3 microsec.
                //Average node computing: 1947 piece
                //Average node apply computing time: 973 piece.
                //Average node backtrack computing time: 974 piece.
                //RUN SUCCESSFUL (total time: 174ms)


//NEW-Pillai6
    // BITSET_SIZE 49 ~ ?    (d=3) - BITSET_SIZE 48 ~ ?  (d=3)
    // BITSET_SIZE 45 ~ ?   (d=3) 
    // BITSET_SIZE 25 ~ 331.32s ?(d=2)
    // BITSET_SIZE 17 ~ 350ms (d=1)
            //n = 17;
            //d = 1;
                //AI Solution: 
                //Average node computing time: 16 microsec. - 14
                //Average node apply computing time: 10 microsec. - 9
                //Average node backtrack computing time: 2 microsec. - 2
                //Average node computing: 18 piece
                //Average node apply computing time: 12 piece.
                //Average node backtrack computing time: 6 piece.
                //RUN SUCCESSFUL (total time: 382ms)
            //n = 25;
            //d = 2;
                //Average node computing time: 12 microsec. - 12
                //Average node apply computing time: 14 microsec. - 13
                //Average node backtrack computing time: 3 microsec. - 3
                //Average node computing: 1299 piece
                //Average node apply computing time: 654 piece.
                //Average node backtrack computing time: 645 piece.
                //RUN SUCCESSFUL (total time: 467ms)
            //n = 45;
            //d = 3;
                //Average node computing time: 22 microsec. - 21
                //Average node apply computing time: 31 microsec. - 30
                //Average node backtrack computing time: 6 microsec. - 5
                //Average node computing: 289235 piece
                //Average node apply computing time: 144617 piece.
                //Average node backtrack computing time: 144618 piece.
                //68.07 s - 51.25 s
                //RUN SUCCESSFUL (total time: 1m 9s) - 53s
            //n = 48;
            //d = 3;
                //Average node computing time : 22 microsec.
                //Average node apply computing time : 31 microsec.
                //Average node backtrack computing time : 6 microsec.
                //Average node computing : 1591203 piece
                //Average node apply computing time : 795601 piece.
                //Average node backtrack computing time : 795602 piece.
                //Nem Talaltam Megoldast!
                //381.98 s - 284.46 s
                //RUN SUCCESSFUL(total time : 6m 25s) - (total time: 4m 45s)
            //n = 49
            //d = 3;
                //Average node computing time : 23 microsec. - 22
                //Average node apply computing time : 32 microsec. - 31
                //Average node backtrack computing time : 6 microsec. - 6
                //Average node computing : 985267 piece
                //Average node apply computing time : 492641 piece.
                //Average node backtrack computing time : 492626 piece.
                //244.70 s - 185.90 s - 173.59 s
                //RUN SUCCESSFUL (total time: 4m 7s) - (total time: 3m 6s) - (total time: 2m 54s)

                //AI Solution :
                //Average node computing time : 18 microsec.
                //Average node apply computing time : 24 microsec.
                //Average node backtrack computing time : 4 microsec.
                //Average node computing : 416754 piece
                //Average node apply computing time : 208425 piece.
                //Average node backtrack computing time : 208329 piece.
                //55.91 s
                //RUN SUCCESSFUL(total time : 56s)

                //AI Solution: - antisimm. shieve 
                //Average node computing time: 18 microsec.
                //Average node apply computing time: 24 microsec.
                //Average node backtrack computing time: 4 microsec.
                //Average node computing: 417784 piece
                //Average node apply computing time: 208940 piece.
                //Average node backtrack computing time: 208844 piece.
                //56.01 s
                //RUN SUCCESSFUL (total time: 57s)

                //Average node computing time: 18 microsec.
                //Average node apply computing time: 24 microsec.
                //Average node backtrack computing time: 4 microsec.
                //Average node computing: 416754 piece
                //Average node apply computing time: 208425 piece.
                //Average node backtrack computing time: 208329 piece.
                //55.85 s
                //RUN SUCCESSFUL (total time: 56s)

                //AI Solution: 
                //Average node computing time: 18 microsec.
                //Average node apply computing time: 24 microsec.
                //Average node backtrack computing time: 5 microsec.
                //Average node computing: 295966 piece
                //Average node apply computing time: 148019 piece.
                //Average node backtrack computing time: 147947 piece.
                //40.74 s
                //RUN SUCCESSFUL (total time: 41s)


 //NEW-Pillai6s
        
        // BITSET_SIZE 17 ~ 200ms (d=1)
                //AI Solution: 
                //Average node computing time: 17 microsec.
                //Average node apply computing time: 8 microsec.
                //Average node backtrack computing time: 1 microsec.
                //Average node computing: 10 piece
                //Average node apply computing time: 8 piece.
                //Average node backtrack computing time: 2 piece.
                //(13, 1); (11, 6); (7, 1); (5, 2); (3, 1); (2, 1); 
                //[2 5 2 3 2 11 2 7 2 3 2 5 2 13 2 3 2 ]
                //State: [00000000000000000]
                //Parent:[00010000000000000]
                //Operator:(13, 1); 
                //App_Operators:
                //chOpType: 13
                //depth: 6
                //maxC: 1
                //evenC: 1
                //oddC: 0
                //0.00 s
                //RUN SUCCESSFUL (total time: 200ms)

        // BITSET_SIZE 25 ~ 331.32s ?(d=2)
                //AI Solution: 
                //Average node computing time: 10 microsec.
                //Average node apply computing time: 11 microsec.
                //Average node backtrack computing time: 2 microsec.
                //Average node computing: 555 piece
                //Average node apply computing time: 282 piece.
                //Average node backtrack computing time: 273 piece.
                //(23, 1); (19, 6); (17, 8); (13, 5); (11, 9); (7, 7); (5, 2); (3, 1); (4, 3); 
                //[3 5 4 3 13 19 4 17 11 3 4 5 3 7 4 3 5 13 4 11 7 3 4 23 3 ]
                //State: [0000000000000000000000000]
                //Parent:[0100000000000000000000000]
                //Operator:(23, 1); 
                //App_Operators:
                //chOpType: 23
                //depth: 9
                //maxC: 1
                //evenC: 1
                //oddC: 0
                //0.01 s
                //RUN SUCCESSFUL (total time: 174ms)

        // BITSET_SIZE 45 ~ ?   (d=3)

        // BITSET_SIZE 48 ~ 9mp (d=3)
            //AI Solution: 
            //Average node computing time: 16 microsec.
            //Average node apply computing time: 22 microsec.
            //Average node backtrack computing time: 4 microsec.
            //Average node computing: 347874 piece
            //Average node apply computing time: 173977 piece.
            //Average node backtrack computing time: 173897 piece.
            //Nem Talaltam Megoldast!
            //9.57 s
            //RUN SUCCESSFUL (total time: 9s)


        // BITSET_SIZE 49 ~ ?    (d=3)
            //AI Solution: 
            //Average node computing time: 17 microsec.
            //Average node apply computing time: 23 microsec.
            //Average node backtrack computing time: 4 microsec.
            //Average node computing: 295966 piece
            //Average node apply computing time: 148019 piece.
            //Average node backtrack computing time: 147947 piece.
            //(47, 1); (43, 6); (41, 4); (37, 1); (31, 5); (29, 20); (23, 3); (19, 14); (17, 7); (13, 8); (11, 7); (7, 2); (6, 1); (5, 2); (9, 1); (4, 3); 
            //[9 5 4 41 31 43 4 13 7 9 4 5 6 19 4 7 5 11 4 29 13 5 4 17 6 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 47 6 ]
            //State: [0000000000000000000000000000000000000000000000000]
            //Parent:[0100000000000000000000000000000000000000000000000]
            //Operator:(47, 1); 
            //App_Operators:
            //chOpType: 47
            //depth: 16
            //maxC: 1
            //evenC: 1
            //oddC: 0
            //8.41 s
            //RUN SUCCESSFUL (total time: 8s)

         
        
//pillai6s2 63,4
//(61, 1); (59, 1); (53, 3); (47, 16); (43, 18); (41, 22); (37, 20); (31, 17); (29, 21); (23, 15); (19, 4); (17, 2); (13, 6); (11, 8); (7, 5); (5, 4); (6, 1); (9, 1); (8, 3); 
//[9 17 8 5 7 13 6 11 5 9 8 7 6 5 23 47 31 43 8 37 29 41 19 5 6 7 8 9 5 11 6 13 7 5 8 17 9 23 5 7 11 19 8 5 13 9 7 31 6 29 8 11 17 5 9 53 37 13 8 59 6 61 11 ]
//State: [000000000000000000000000000000000000000000000000000000000000000]
//Parent:[010000000000000000000000000000000000000000000000000000000000000]
//Operator:(61, 1); 
//App_Operators:
//chOpType: 0
//depth: 19
//maxC: 1
//evenC: 1
//oddC: 0
//
//
//158.53 s
//
//
//RUN SUCCESSFUL (total time: 2m 38s)




//--------------------------------------------------------------------------------------------------------------------------------------------
// BITSET_SIZE 49 ~ 20mp
//AI Solution: 
//[9 5 4 41 31 43 4 13 7 9 4 5 6 19 4 7 5 11 4 29 13 5 4 17 6 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 47 6 ]
//[9 5 4 41 31 43 4 13 7 9 4 5 6 19 4 7 5 11 4 29 13 5 4 17 6 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 47 6 ]
//[9 5 4 41 31 43 4 13 7 9 4 5 6 19 4 7 5 11 4 29 13 5 4 17 6 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 47 6 ]
//[9 5 4 41 31 43 4 13 7 9 4 5 6 19 4 7 5 11 4 29 13 5 4 17 6 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 0 6 ]
//(47, 1); 
//EMPTY
//DEPTH: 15
//OP_TYPE: 0
//NOF_ZEROS: 0
//COV_CAPN: 1 1 0
//Elapsed Time: 20 sec. Number of clock ticks: 20980000.

//[9 5 4 41 31 43 4 13 7 9 4 5 0 19 4 7 5 11 4 29 13 5 4 17 0 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 47 23 ]
//[9 5 4 41 31 43 4 13 7 9 4 5 6 19 4 7 5 11 4 29 13 5 4 17 6 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 47 6 ]
//State: [1111111111111111111111111111111111111111111111111]
//Parent:[1011111111111111111111111111111111111111111111111]
//Operator:(47, 1); 
//App_Operators:
//chOpType: 47
//depth: 15
//maxC: 1
//evenC: 1
//oddC: 0


// BITSET_SIZE 25 ~ 200ms (d=2)
//AI Solution: 
//[3 5 4 3 13 19 4 17 11 3 4 5 3 7 4 3 5 13 4 11 7 3 4 23 3 ]
//[3 5 4 3 13 19 4 17 11 3 4 5 3 7 4 3 5 13 4 11 7 3 4 0 3 ]
//(23, 1); 
//EMPTY
//DEPTH: 9
//OP_TYPE: 0
//NOF_ZEROS: 0
//COV_CAPN: 1 1 0
//Elapsed Time: 0 sec. Number of clock ticks: 10000.

// BITSET_SIZE 17 ~ 200ms (d=1)
//AI Solution: 
//[2 5 2 3 2 11 2 7 2 3 2 5 2 13 2 3 2 ]
//[2 5 2 3 2 11 2 7 2 3 2 5 2 0 2 3 2 ]
//(13, 1); 
//EMPTY
//DEPTH: 6
//OP_TYPE: 0
//NOF_ZEROS: 0
//COV_CAPN: 1 1 0
//Elapsed Time: 0 sec. Number of clock ticks: 0.

//--------------------------------------------------------------------------------------------
//Number of input parameters not adequate!
//AI Solution: 
//[9 5 4 41 31 43 4 13 7 9 4 5 6 19 4 7 5 11 4 29 13 5 4 17 6 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 47 6 ]
//[9 5 4 41 31 43 4 13 7 9 4 5 6 19 4 7 5 11 4 29 13 5 4 17 6 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 0 6 ]
//(47, 1); 
//EMPTY
//DEPTH: 15
//OP_TYPE: 0
//NOF_ZEROS: 0
//COV_CAPN: 1 1 0
//
//
//[6 47 4 9 41 7 4 5 17 11 4 37 9 31 4 13 19 5 4 7 11 9 4 23 6 17 4 5 13 29 4 11 5 7 4 19 6 5 4 9 7 13 4 43 31 41 4 5 9 ]
//[6 0 4 9 41 7 4 5 17 11 4 37 9 31 4 13 19 5 4 7 11 9 4 23 6 17 4 5 13 29 4 11 5 7 4 19 6 5 4 9 7 13 4 43 31 41 4 5 9 ]
//(47, 2); 
//EMPTY
//DEPTH: 15
//OP_TYPE: 0
//NOF_ZEROS: 0
//COV_CAPN: 1 1 0
//
//
//Average node computing time: 15 microsec.
//Average node apply computing time: 16 microsec.
//Average node backtrack computing time: 6 microsec.
//Average node computing: 2105395 piece
//Average node apply computing time: 1052697 piece.
//Average node backtrack computing time: 1052698 piece.
//Nem Talaltam Megoldast!
//402.46 s
//
//
//RUN SUCCESSFUL (total time: 6m 42s)

//AI Solution: 
//(47, 1); (43, 6); (41, 4); (37, 1); (31, 5); (29, 20); (23, 3); (19, 14); (17, 7); (13, 8); (11, 7); (7, 2); (6, 1); (5, 2); (9, 1); (4, 3); 
//[9 5 4 41 31 43 4 13 7 9 4 5 6 19 4 7 5 11 4 29 13 5 4 17 6 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 47 6 ]
//[9 5 4 41 31 43 4 13 7 9 4 5 6 19 4 7 5 11 4 29 13 5 4 17 6 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 47 6 ]
//State: [0000000000000000000000000000000000000000000000000]
//Parent:[0100000000000000000000000000000000000000000000000]
//Operator:(47, 1); 
//App_Operators:
//chOpType: 47
//depth: 16
//maxC: 1
//evenC: 1
//oddC: 0
//
//
//(47, 2); (43, 1); (41, 5); (37, 12); (31, 14); (29, 1); (23, 1); (19, 17); (17, 9); (13, 3); (11, 10); (7, 6); (6, 1); (5, 3); (9, 4); (4, 3); 
//[6 47 4 9 41 7 4 5 17 11 4 37 9 31 4 13 19 5 4 7 11 9 4 23 6 17 4 5 13 29 4 11 5 7 4 19 6 5 4 9 7 13 4 43 31 41 4 5 9 ]
//State: [0000000000000000000000000000000000000000000000000]
//Parent:[0000000000000000000000000000000000000000000000010]
//Operator:(47, 2); 
//App_Operators:
//chOpType: 47
//depth: 16
//maxC: 1
//evenC: 1
//oddC: 0
//
//
//Average node computing time: 24 microsec.
//Average node apply computing time: 34 microsec.
//Average node backtrack computing time: 6 microsec.
//Average node computing: 2652349 piece
//Average node apply computing time: 1326174 piece.
//Average node backtrack computing time: 1326175 piece.
//Nem Talaltam Megoldast!
//551.89 s
//
//
//RUN SUCCESSFUL (total time: 9m 13s)

//AI Solution :
//(47, 1);
//(43, 6);
//(41, 4);
//(37, 1);
//(31, 5);
//(29, 20);
//(23, 3);
//(19, 14);
//(17, 7);
//(13, 8);
//(11, 7);
//(7, 2);
//(6, 1);
//(5, 2);
//(9, 1);
//(4, 3);
//[9 5 4 41 31 43 4 13 7 9 4 5 6 19 4 7 5 11 4 29 13 5 4 17 6 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 47 6 ]
//[9 5 4 41 31 43 4 13 7 9 4 5 6 19 4 7 5 11 4 29 13 5 4 17 6 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 47 6 ]
//State : [0000000000000000000000000000000000000000000000000]
//Parent : [0100000000000000000000000000000000000000000000000]
//Operator : (47, 1);
//App_Operators:
//chOpType : 47
//depth : 16
//maxC : 1
//evenC : 1
//oddC : 0
//
//
//(47, 2);
//(43, 1);
//(41, 5);
//(37, 12);
//(31, 14);
//(29, 1);
//(23, 1);
//(19, 17);
//(17, 9);
//(13, 3);
//(11, 10);
//(7, 6);
//(6, 1);
//(5, 3);
//(9, 4);
//(4, 3);
//[6 47 4 9 41 7 4 5 17 11 4 37 9 31 4 13 19 5 4 7 11 9 4 23 6 17 4 5 13 29 4 11 5 7 4 19 6 5 4 9 7 13 4 43 31 41 4 5 9 ]
//State : [0000000000000000000000000000000000000000000000000]
//Parent : [0000000000000000000000000000000000000000000000010]
//Operator : (47, 2);
//App_Operators:
//chOpType : 47
//depth : 16
//maxC : 1
//evenC : 1
//oddC : 0
//
//
//Average node computing time : 23 microsec.
//Average node apply computing time : 32 microsec.
//Average node backtrack computing time : 6 microsec.
//Average node computing : 1989127 piece
//Average node apply computing time : 994642 piece.
//Average node backtrack computing time : 994485 piece.
//Nem Talaltam Megoldast!
//378.43 s
//RUN SUCCESSFUL(total time : 6m 19s)
//
//Average node computing time: 17 microsec.
//Average node apply computing time: 23 microsec.
//Average node backtrack computing time: 4 microsec.
//Average node computing: 920025 piece
//Average node apply computing time: 460091 piece.
//Average node backtrack computing time: 459934 piece.
//Nem Talaltam Megoldast!
//121.29 s
//RUN SUCCESSFUL (total time: 2m 2s)

// - antisimm. shieve
//Average node computing time: 18 microsec.
//Average node apply computing time: 23 microsec.
//Average node backtrack computing time: 4 microsec.
//Average node computing: 920993 piece
//Average node apply computing time: 460575 piece.
//Average node backtrack computing time: 460418 piece.
//Nem Talaltam Megoldast!
//121.74 s
//RUN SUCCESSFUL (total time: 2m 2s)
//Average node computing time: 18 microsec.
//Average node apply computing time: 24 microsec.
//Average node backtrack computing time: 5 microsec.
//Average node computing: 445345 piece
//Average node apply computing time: 222712 piece.
//Average node backtrack computing time: 222633 piece.
//Nem Talaltam Megoldast!
//59.76 s
//RUN SUCCESSFUL (total time: 1m 0s)

//AI Solution :
//(47, 1);
//(43, 6);
//(41, 4);
//(37, 1);
//(31, 5);
//(29, 20);
//(23, 3);
//(19, 14);
//(17, 7);
//(13, 8);
//(11, 7);
//(7, 2);
//(6, 1);
//(5, 2);
//(9, 1);
//(4, 3);
//[9 5 4 41 31 43 4 13 7 9 4 5 6 19 4 7 5 11 4 29 13 5 4 17 6 23 4 9 11 7 4 5 19 13 4 31 9 37 4 11 17 5 4 7 41 9 4 47 6 ]
//State : [0000000000000000000000000000000000000000000000000]
//Parent : [0100000000000000000000000000000000000000000000000]
//Operator : (47, 1);
//App_Operators:
//chOpType : 47
//depth : 16
//maxC : 1
//evenC : 1
//oddC : 0
//Average node computing time : 17 microsec.
//Average node apply computing time : 22 microsec.
//Average node backtrack computing time : 4 microsec.
//Average node computing : 445345 piece
//Average node apply computing time : 222712 piece.
//Average node backtrack computing time : 222633 piece.
//Nem Talaltam Megoldast!
//12.38 s
//RUN SUCCESSFUL(total time : 12s)
