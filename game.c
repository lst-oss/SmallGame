#include "game.h"

int x = 0;
int y = 0;

void Menu()
{
	printf("##########################\n");
	printf("## 1.play     0.exit    ##\n");
	printf("##########################\n");
	printf("Please select ##");
}

int ChessCount(int board[][COL], enum Dir d)
{
    int _x = x;
    int _y = y;
    
    int count = 0;
    while(1){
      switch(d){
        case LEFT:
          _y--;
          break;
        case RIGHT:
          _y++;
          break;
        case UP:
          _x--;
          break;
        case DOWN:
          _x++;
          break;
        case LEFT_UP:
          _x--, _y--;
          break;
        case RIGHT_DOWN:
          _x++, _y++;
          break;
        case RIGHT_UP:
          _x--, _y++;
          break;
        case LEFT_DOWN:
          _x++, _y--;
          break;
     }
      if(_x < 0 || _x > ROW-1 || _y < 0 || _y > COL-1){ //坐标移动完毕，一定要先保证没有越界
          break;
     }
      if(board[x][y] == board[_x][_y]){ //判定指定位置和原始位置的棋子是否相同，“连珠”就体现在这里
          count++;
     }
      else{
          break;
     }
   }                            
    return count;
}

int IsOver(int board[][COL], int row, int col)
{
	// hard
     int count1 = ChessCount(board, LEFT) + ChessCount(board, RIGHT) + 1;
    int count2 = ChessCount(board, UP) + ChessCount(board, DOWN) + 1;
    int count3 = ChessCount(board, LEFT_UP) + ChessCount(board, RIGHT_DOWN) + 1;
    int count4 = ChessCount(board, LEFT_DOWN) + ChessCount(board, RIGHT_UP) + 1;

    if(count1 >= 5 || count2 >= 5 || count3 >= 5 || count4 >= 5)
    {
        if (board[x-1][y-1] == PLAYER1){
            return PLAYER1_WIN;}
        else{
            return PLAYER2_WIN;}
    }

    for(int i = 0;i<ROW;++i)
    {
        for(int j=0;j<COL;++j)
        {
            if(board[i][j] == 0)
            {               
                return NEXT;
            }
        }
    }
    return DRAW;
}

void ShowBoard(int board[][COL],int row, int col)
{
	//将数组内容可视化
    // printf("\e[1;1H\e[2J");
    printf("\033c");
    printf("\n ");
    for(int i = 0; i < col; i++){
        printf("%3d", i);
    }
    printf("\n");
    for(int i = 0; i < row; i++){
        printf("%-3d", i);
        for(int j = 0; j < col; j++){
            if(board[i][j] == PLAYER1){
               //player1
                 printf(" ● ");
               // printf(" X ");
           }
            else if(board[i][j] == PLAYER2){
                //player2
                printf(" ○ ");
              // printf(" O ");
           }else{
                //Space
                printf(" . ");
           }
       }
        printf("\n");
   }
}

	
void PlayerMove(int board[ROW][COL], int who)    
{    
    while(1){    
        printf("\nPlayer[ %d ] Please Enter Your Postion# ", who);    
        scanf("%d%d", &x, &y); 
        if(x<0 || y > COL){    //这里的x，y是全局的，每次都记录着当前用户的落子位置
            printf("Postion Error!\n");
       }    
        else if(board[x][y] != 0){    
            printf("Postion Is Occupied!\n");    
       }
        else{    
            board[x][y] = who;    //谁落子，就放置谁的数据
            break;    
       }    
   }    
} 


void Game()
{

	int board[ROW][COL];
	memset(board, 0, sizeof(board));
	int result = NEXT;
     do{
		ShowBoard(board, ROW, COL);
		PlayerMove(board, PLAYER1);
		result = IsOver(board, ROW, COL);
		if(NEXT != result)
		{
			break;
		}
        ShowBoard(board, ROW, COL);
		PlayerMove(board,  PLAYER2);
		result = IsOver(board, ROW, COL);
		if (NEXT != result)
		{
			break;
		}
	}
	while(1);

	switch(result){
		case PLAYER1_WIN:
			printf("恭喜用户1,you have won\n");
			break;
		case PLAYER2_WIN:
			printf("恭喜用户2,you have won!\n");
			break;
		case DRAW:
			printf("平局！\n");
			break;
		default:
			break;
	}
}

