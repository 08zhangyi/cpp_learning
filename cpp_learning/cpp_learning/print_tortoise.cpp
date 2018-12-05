#include <iostream>
using namespace std;
const int COMMANDS = 100, SIZE = 40;  //这里SIZE为展示画板大小，由于原本行列间隔不一样，为美观我将行间隔
int turnRight(int);                //一个空位,COMMANDS为命令输入上限，为后面创建命令数组使用
int turnLeft(int);
void getCommands(int[][2]);
void movePen(int, int[][SIZE], int, int);
void printArray(const int[][SIZE]);

int main()
{
	int floor[SIZE][SIZE] = { 0 };
	int commands = 0;
	static int direction = 0;  //记录方向
	int commandArray[COMMANDS][2] = { 0 };  //储存命令
	int count = 0;
	int distance = 0;
	bool penDown = false;
	getCommands(commandArray);
	commands = commandArray[count][0];
	while (commands != 9)
	{
		//cout << "commands:" << commands << endl;//测试用
		switch (commands)
		{
		case 1:
			penDown = false;
			break;
		case 2:
			penDown = true;
			break;
		case 3:
			direction = turnRight(direction);
			break;
		case 4:
			direction = turnLeft(direction);
			break;
		case 5:
			distance = commandArray[count][1];
			movePen(penDown, floor, direction, distance);
			break;
		case 6:
			cout << "\nThe drawing is:\n\n";
			printArray(floor);
			break;
		default:
			break;
		}
		commands = commandArray[++count][0];  //从数组中取出命令
	}
	system("pause");
	return 0;
}

void getCommands(int commands[][2])
{
	int tempCommand, i;
	cout << "Enter command(9 to end input): ";
	cin >> tempCommand;
	for (i = 0; tempCommand != 9 && i<COMMANDS; i++)
	{
		commands[i][0] = tempCommand;
		if (tempCommand == 5)
		{
			cin.ignore();  //忽略5后面的字符','
			cin >> commands[i][1];  //将移动距离保存在commands[i][1]中。
		}
		cout << "Enter command(9 to end input): ";
		cin >> tempCommand;
	}
	commands[i][0] = 9;
}

int turnRight(int dir)
{
	return ++dir > 3 ? 0 : dir;  //原点为0，右转4次回到原点
}
int turnLeft(int dir)
{
	return --dir < 0 ? 3 : dir;
}
void movePen(int down, int a[][SIZE], int dir, int dis)
{
	static int xPosition = 0, yPosition = 0;  //设置原点
	int xTemp, yTemp, i;
	xTemp = xPosition;
	yTemp = yPosition;
	//cout << "Direction:" << dir << " Pen：" << down << endl;//测试用 
	switch (dir)
	{
	case 0:
		for (i = 0; i < dis * 2 && (yTemp + i)<SIZE; i += 2)
		{
			if (down)
			{
				a[xTemp][yTemp + i] = 1;
			}
			else if (down == 0)
			{
				a[xTemp][yTemp + i] = 0;
			}
			xPosition = xTemp;
			yPosition = yTemp + i;
		}
		break;
	case 1:
		for (i = 0; i < dis && (xTemp + i)<SIZE; ++i)
		{
			if (down)
			{
				a[xTemp + i][yTemp] = 1;
			}
			else if (down == 0)
			{
				a[xTemp + i][yTemp] = 0;
			}
			xPosition = xTemp + i;
			yPosition = yTemp;
		}
		break;
	case 2:
		for (i = 0; i < dis * 2 && (yTemp - i) >= 0; i += 2) //加2是为了让行和列的间隔一样，单纯美观
		{
			if (down)
			{
				a[xTemp][yTemp - i] = 1;
			}
			else if (down == 0)
			{
				a[xTemp][yTemp - i] = 0;
			}
			xPosition = xTemp;
			yPosition = yTemp - i;
		}
		break;
	case 3:
		for (i = 0; i < dis && (xTemp - i) >= 0; ++i)
		{
			if (down)
			{
				a[xTemp - i][yTemp] = 1;
			}
			else if (down == 0)
			{
				a[xTemp - i][yTemp] = 0;
			}
			xPosition = xTemp - i;
			yPosition = yTemp;
		}
		break;
	}
}
void printArray(const int a[][SIZE])
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (a[i][j] == 0) cout << " ";
			else cout << "*";
		}
		cout << endl;
	}
}