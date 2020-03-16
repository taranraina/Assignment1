#pragma once
class Card
{

public:
	Card(int);

private:
	int id;
	

};

/*vector<Node*> boardMap;

cout << "		 ------------------------------------------------------------------------------         " << endl;
cout << "		|	0	|	1	|	2	|	3	|	     4	|        " << endl;
cout << " ------------------------------------------------------------------------------------------------------------ " << endl;
cout << "|	5	|	6	|	7	|	8	|	9	|		10	|	11   |" << endl;
cout << "|------------------------------------------------------------------------------------------------------------" << endl;
cout << "|	12	|	13	|	14	|	15	|	16	|		17	|	18 	 |" << endl;
cout << "|------------------------------------------------------------------------------------------------------------" << endl;
cout << "|	19	|	20	|	21	|	22	|	23	|		24	|	25 	 |" << endl;
cout << "|------------------------------------------------------------------------------------------------------------" << endl;
cout << "|	26	|	27	|	28	|	29	|	30	|		31	|	32 	 |" << endl;
cout << "|------------------------------------------------------------------------------------------------------------" << endl;
cout << "|	33	|	34	|	35	|	36	|	37	|		38	|	39 	 |" << endl;
cout << " ------------------------------------------------------------------------------------------------------------ " << endl;
cout << "		|	40	|	41	|	42	|	43	|	    44	|        " << endl;
cout << "		 --------------------------------------- ---------------------------------------         " << endl;

Node* tile0 = new Node(0);
Node* tile1 = new Node(1);
Node* tile2 = new Node(2);
Node* tile3 = new Node(3);
Node* tile4 = new Node(4);
Node* tile5 = new Node(5);
Node* tile6 = new Node(6);
Node* tile7 = new Node(7);
Node* tile8 = new Node(8);
Node* tile9 = new Node(9);
Node* tile10 = new Node(10);
Node* tile11 = new Node(11);
Node* tile12 = new Node(12);
Node* tile13 = new Node(13);
Node* tile14 = new Node(14);
Node* tile15 = new Node(15);
Node* tile16 = new Node(16);
Node* tile17 = new Node(17);
Node* tile18 = new Node(18);
Node* tile19 = new Node(19);
Node* tile20 = new Node(20);
Node* tile21 = new Node(21);
Node* tile22 = new Node(22);
Node* tile23 = new Node(23);
Node* tile24 = new Node(24);
Node* tile25 = new Node(25);
Node* tile26 = new Node(26);
Node* tile27 = new Node(27);
Node* tile28 = new Node(28);
Node* tile29 = new Node(29);
Node* tile30 = new Node(30);
Node* tile31 = new Node(31);
Node* tile32 = new Node(32);
Node* tile33 = new Node(33);
Node* tile34 = new Node(34);
Node* tile35 = new Node(35);
Node* tile36 = new Node(36);
Node* tile37 = new Node(37);
Node* tile38 = new Node(38);
Node* tile39 = new Node(39);
Node* tile40 = new Node(40);
Node* tile41 = new Node(41);
Node* tile42 = new Node(42);
Node* tile43 = new Node(43);
Node* tile44 = new Node(44);

boardMap.push_back(tile0);
boardMap.push_back(tile1);
boardMap.push_back(tile2);
boardMap.push_back(tile3);
boardMap.push_back(tile4);
boardMap.push_back(tile5);
boardMap.push_back(tile6);
boardMap.push_back(tile7);
boardMap.push_back(tile8);
boardMap.push_back(tile9);
boardMap.push_back(tile10);
boardMap.push_back(tile11);
boardMap.push_back(tile12);
boardMap.push_back(tile13);
boardMap.push_back(tile14);
boardMap.push_back(tile15);
boardMap.push_back(tile16);
boardMap.push_back(tile17);
boardMap.push_back(tile18);
boardMap.push_back(tile19);
boardMap.push_back(tile20);
boardMap.push_back(tile21);
boardMap.push_back(tile22);
boardMap.push_back(tile23);
boardMap.push_back(tile24);
boardMap.push_back(tile25);
boardMap.push_back(tile26);
boardMap.push_back(tile27);
boardMap.push_back(tile28);
boardMap.push_back(tile29);
boardMap.push_back(tile30);
boardMap.push_back(tile31);
boardMap.push_back(tile32);
boardMap.push_back(tile33);
boardMap.push_back(tile34);
boardMap.push_back(tile35);
boardMap.push_back(tile36);
boardMap.push_back(tile37);
boardMap.push_back(tile38);
boardMap.push_back(tile39);
boardMap.push_back(tile40);
boardMap.push_back(tile41);
boardMap.push_back(tile42);
boardMap.push_back(tile43);
boardMap.push_back(tile44);

tile0->setRight(tile1);
tile0->setBottom(tile6);

tile1->setLeft(tile0);
tile1->setRight(tile2);
tile1->setBottom(tile7);

tile2->setLeft(tile1);
tile2->setRight(tile3);
tile2->setBottom(tile8);


tile3->setLeft(tile2);
tile3->setRight(tile4);
tile3->setBottom(tile9);

tile4->setLeft(tile3);
tile4->setBottom(tile10);

tile5->setRight(tile6);
tile5->setBottom(tile12);

tile6->setTop(tile0);
tile6->setLeft(tile5);
tile6->setRight(tile7);
tile6->setBottom(tile13);

tile7->setTop(tile1);
tile7->setLeft(tile6);
tile7->setRight(tile8);
tile7->setBottom(tile14);

tile8->setTop(tile2);
tile8->setLeft(tile7);
tile8->setRight(tile9);
tile8->setBottom(tile15);

tile9->setTop(tile1);
tile9->setLeft(tile6);
tile9->setRight(tile8);
tile9->setBottom(tile14);

tile10->setTop(tile4);
tile10->setLeft(tile9);
tile10->setRight(tile11);
tile10->setBottom(tile17);

tile11->setLeft(tile10);
tile11->setBottom(tile18);

tile12->setTop(tile5);
tile12->setRight(tile13);
tile12->setBottom(tile19);

tile13->setTop(tile6);
tile13->setLeft(tile12);
tile13->setRight(tile14);
tile13->setBottom(tile20);

tile14->setTop(tile7);
tile14->setLeft(tile13);
tile14->setRight(tile15);
tile14->setBottom(tile21);

tile15->setTop(tile9);
tile15->setLeft(tile14);
tile15->setRight(tile16);
tile15->setBottom(tile22);

tile16->setTop(tile9);
tile16->setLeft(tile15);
tile16->setRight(tile17);
tile16->setBottom(tile23);

tile17->setTop(tile10);
tile17->setLeft(tile16);
tile17->setRight(tile18);
tile17->setBottom(tile24);

tile18->setTop(tile11);
tile18->setLeft(tile17);
tile18->setBottom(tile25);

tile19->setTop(tile12);
tile19->setRight(tile20);
tile19->setBottom(tile26);

tile20->setTop(tile13);
tile20->setLeft(tile19);
tile20->setRight(tile21);
tile20->setBottom(tile27);

tile21->setTop(tile14);
tile21->setLeft(tile28);
tile21->setRight(tile20);
tile21->setBottom(tile22);

tile22->setTop(tile15);
tile22->setLeft(tile21);
tile22->setRight(tile23);
tile22->setBottom(tile29);

tile23->setTop(tile16);
tile23->setLeft(tile22);
tile23->setRight(tile24);
tile23->setBottom(tile30);

tile24->setTop(tile17);
tile24->setLeft(tile23);
tile24->setRight(tile25);
tile24->setBottom(tile31);

tile25->setTop(tile18);
tile25->setLeft(tile24);
tile25->setBottom(tile32);

tile26->setTop(tile19);
tile26->setRight(tile27);
tile26->setBottom(tile33);

tile27->setTop(tile20);
tile27->setLeft(tile26);
tile27->setRight(tile28);
tile27->setBottom(tile34);


tile28->setTop(tile21);
tile28->setLeft(tile27);
tile28->setRight(tile29);
tile28->setBottom(tile35);

tile29->setTop(tile22);
tile29->setLeft(tile28);
tile29->setRight(tile30);
tile29->setBottom(tile36);


tile30->setTop(tile23);
tile30->setLeft(tile29);
tile30->setRight(tile31);
tile30->setBottom(tile37);

tile31->setTop(tile24);
tile31->setLeft(tile30);
tile31->setRight(tile32);
tile31->setBottom(tile38);

tile32->setTop(tile25);
tile32->setLeft(tile31);
tile32->setBottom(tile39);

tile33->setTop(tile26);
tile33->setRight(tile34);

tile34->setTop(tile27);
tile34->setLeft(tile33);
tile34->setRight(tile35);
tile34->setBottom(tile40);

tile35->setTop(tile28);
tile35->setLeft(tile34);
tile35->setRight(tile36);
tile35->setBottom(tile41);

tile36->setTop(tile29);
tile36->setLeft(tile35);
tile36->setRight(tile37);
tile36->setBottom(tile42);

tile37->setTop(tile30);
tile37->setLeft(tile36);
tile37->setRight(tile38);
tile37->setBottom(tile43);

tile38->setTop(tile31);
tile38->setLeft(tile32);
tile38->setRight(tile39);
tile38->setBottom(tile44);

tile39->setTop(tile32);
tile39->setLeft(tile38);

tile40->setTop(tile34);
tile40->setRight(tile41);

tile41->setTop(tile35);
tile41->setLeft(tile40);
tile41->setRight(tile42);

tile42->setTop(tile36);
tile42->setLeft(tile41);
tile42->setRight(tile43);

tile43->setTop(tile37);
tile43->setLeft(tile42);
tile43->setRight(tile44);

tile44->setTop(tile38);
tile44->setLeft(tile43);
*/