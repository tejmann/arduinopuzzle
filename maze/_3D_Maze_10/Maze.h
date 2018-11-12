
// The maze itself and routines to check where the walls are

//== Maze ==
byte maze[][2] = {
    {B10111111, B11111111},
    {B10000000, B00000001},
    {B10000000, B00000001},
    {B10000000, B00000001},
    {B10000000, B00000001},
    {B10000000, B00000001},
    {B10000000, B00000001},
    {B11111111, B11111111},
};

byte mazeColMax = 16;
byte mazeRowMax = 8;

#define FacingNorth 0
#define FacingEast 1
#define FacingSouth 2
#define FacingWest 3

int youRow, youCol;               // player's location
int youDir = 0;                   // [0,1,2,3]=[N,E,S,W]
int youRotDir = 0;                // [-1,0,1]= turn [left,0,right]
int youRowDir = 0, youColDir = 0; // player's status of directions

bool hasFrontLeftWall;
bool hasFrontWall;
bool hasFrontRightWall;
bool hasBackLeftWall;
bool hasBackWall;
bool hasBackRightWall;

void ResetMaze()
{
  youCol = 2;     //[1-14]
  youRow = 6;   //[1-6]
  youDir = FacingNorth;
}

bool Look(byte row, byte col)
{
  if (row < 0 || row > mazeRowMax || col < 0 || col > mazeColMax)
  {
    return false;
  }
  else
  {
    int colByte = col / 8;
    return bitRead(maze[row][colByte], 7 - (col % 8));
  }
}

void LookNorth(byte row, byte col)
{
  hasFrontLeftWall = Look(row, col - 1);
  hasFrontWall = Look(row, col);
  hasFrontRightWall = Look(row, col + 1);
  hasBackLeftWall = Look(row - 1, col - 1);
  hasBackWall = Look(row - 1, col);
  hasBackRightWall = Look(row - 1, col + 1);
}

void LookEast(byte row, byte col)
{
  hasFrontLeftWall = Look(row - 1, col);
  hasFrontWall = Look(row, col);
  hasFrontRightWall = Look(row + 1, col);
  hasBackLeftWall = Look(row - 1, col + 1);
  hasBackWall = Look(row, col + 1);
  hasBackRightWall = Look(row + 1, col + 1);
}

void LookSouth(byte row, byte col)
{
  hasFrontLeftWall = Look(row, col + 1);
  hasFrontWall = Look(row, col);
  hasFrontRightWall = Look(row, col - 1);
  hasBackLeftWall = Look(row + 1, col + 1);
  hasBackWall = Look(row + 1, col);
  hasBackRightWall = Look(row + 1, col - 1);
}

void LookWest(byte row, byte col)
{
  hasFrontLeftWall = Look(row + 1, col);
  hasFrontWall = Look(row, col);
  hasFrontRightWall = Look(row - 1, col);
  hasBackLeftWall = Look(row + 1, col - 1);
  hasBackWall = Look(row, col - 1);
  hasBackRightWall = Look(row - 1, col - 1);
}
