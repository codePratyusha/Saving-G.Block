
#include "zombie.h"
#include <iostream>
#include <QTimer>
#include "gamewindow.h"
#include <queue>
#include <map>
#include <vector>


extern GameWindow* game;


//Constructor
//@def constructs a zombie object and initializes the position to 0,0
Zombie::Zombie(QPixmap& pixmap) : QObject(), QGraphicsPixmapItem(pixmap) {
  //create Zombie and set size

   // QPixmap zombiePix(":/images/zombieRight.png");
   // setPixmap(zombiePix);
    //zombiePix.scaled(0,0);
            x_pos = pos().x();
            y_pos = pos().y();
            health = 100;
            isDead = false;
            direction = 'R';
            k = 0;

            //QTimer* timer = new QTimer(this);
            timer->singleShot(1000,this,SLOT(moveToGene()));
            //connect(timer, SIGNAL(timeout()), this, SLOT(moveToGene()));

              //start the timer (call move every 50 ms)
              //timer->start(50);

}


//Destructor
Zombie::~Zombie(){}

//Zombie moves across screen - function is called everytime the key is pressed

// @brief






//void Zombie::move(){

//int speed = 1;

//if(direction=='R'){
// setPos(x()+speed, y());
//}else if(direction=='L'){
//  setPos(x()-speed, y());
//}else if(direction=='U'){
//    setPos(x(), y()- speed);
//}else if(direction =='D'){
//    setPos(x(), y()+ speed);
//}


//if out of bounds, delete zombie

//if(x()>680 || y()>680){

//    scene()->removeItem(this);
//    delete this;

//}



//void findPathFromMap(std::map<std::pair<int,int>, std::pair<int,int>> &map, int source_x, int source_y, int target_x, int target_y){

//    std::vector<std::pair<int,int>> mypath;

//    //Store target pair
//    mypath.push_back({target_x, target_y});

//    //Store parents of target pair


//    int key_x=target_x;
//    int key_y=target_y;

//    //find parents of current nodes and store in the vector

//            while(key_x!=source_x && key_y != source_y){
//                std::pair<int,int> p = map.find({key_x,key_y})->second;
//                mypath.push_back(p);
//                key_x = p.first;
//                key_y = p.second;
//            }

//            mypath.push_back({source_x, source_y});

//    //reverse vector to get path right way round
//            std::reverse(mypath.begin(),mypath.end());

//     //iterate through the reversed vector



//}

void Zombie::setPathToGene(){

    int row_src = 10;  //replace hardcoded values with params
    int col_src = 23;

    int R=26;
    int C= 31;

    int visited[26][31];
    char m[26][31];

    for(int i=0; i<26; i++){
        for(int j=0; j< 31; j++){
            visited[i][j]=false;
        }
    }

    for(int i=0; i<26; i++){
        for(int j=0; j< 31; j++){
            m[i][j]='.';
        }
    }

    m[16][16]= 'E';

    //Declare a map that has Nodes for their key values and parents for their mapped values
    std::map<std::pair<int,int>, std::pair<int,int>> mymap;

    struct Node{
       public:
           int row;
           int col;
           Node* parent;
           Node(int x, int y, Node* p) : row(x), col(y) , parent(p){}
           //Node(),

       };

        Node source(row_src, col_src, nullptr);

       // applying BFS on matrix cells starting from source
           std::queue<Node> q;
           q.push(source);
           visited[source.row][source.col] = true;  //source node has null ptr to parents

           while (!q.empty()) {
               Node p = q.front();
               q.pop();

               // Destination found- if p node is the end node//
               if (m[p.row][p.col] == 'E'){
                   std::pair<int,int> c = std::pair<int, int>(p.row,p.col);
                   std::pair<int,int> parent = std::pair<int, int>(p.parent->row, p.parent->col);
                   mymap.insert(std::pair<std::pair<int,int>,std::pair<int,int>>(c, parent));
                   }

                 //std::cout<< "parentRowB: "<<p.row << " parentY: " << p.col<< std::endl;
                // std::cout<< "parentRow: "<<p.parent->row << " parentY: " << p.parent->col<< std::endl;

               // moving up
               if (p.row - 1 >= 0 && visited[p.row - 1][p.col] == false) {
                   Node current(p.row-1,p.col, &p);

                   if(current.parent!= nullptr && current.parent!= nullptr){
                   current.parent->row = p.row;
                   current.parent->col = p.col;
                   q.push(current);


                   //set current Node as a key
                     //set current Node's parents as its mapped value
                   std::pair<int,int> c = std::pair<int, int>(p.row-1,p.col);
                   std::pair<int,int> parent = std::pair<int, int>(current.parent->row, current.parent->col);
                   mymap.insert(std::pair<std::pair<int,int>,std::pair<int,int>>(c, parent));
                   }
                  // q.push(Node(p.row - 1, p.col));
                   visited[p.row - 1][p.col] = true;
               }

               // moving down
               if (p.row + 1 < R && visited[p.row + 1][p.col] == false) {
                   Node current(p.row+1,p.col, &p);
                   if(current.parent!= nullptr && current.parent!= nullptr){
                                  current.parent->row = p.row;
                                  current.parent->col = p.col;
                                  q.push(current);
                                  std::pair<int,int> c = std::pair<int, int>(p.row+1,p.col);
                                  std::pair<int,int> parent = std::pair<int, int>(current.parent->row, current.parent->col);
                                  mymap.insert(std::pair<std::pair<int,int>,std::pair<int,int>>(c, parent));
}
                  // q.push(QItem(p.row + 1, p.col, p.row, p.col));
                   visited[p.row + 1][p.col] = true;
               }

               // moving left
               if (p.col - 1 >= 0 && visited[p.row][p.col - 1] == false) {

                   Node current(p.row,p.col-1, &p);
                   if(current.parent!= nullptr && current.parent!= nullptr){
                                  current.parent->row = p.row;
                                  current.parent->col = p.col;
                                  q.push(current);
                                  std::pair<int,int> c = std::pair<int, int>(p.row,p.col-1);
                                  std::pair<int,int> parent = std::pair<int, int>(current.parent->row, current.parent->col);
                                  mymap.insert(std::pair<std::pair<int,int>,std::pair<int,int>>(c, parent));
                   }
                   //q.push(QItem(p.row, p.col - 1, p.row, p.col));
                   visited[p.row][p.col - 1] = true;
               }

                // moving right
               if (p.col + 1 < C && visited[p.row][p.col + 1] == false) {

                   Node current(p.row, p.col+1, &p);
                   if(current.parent!= nullptr && current.parent!= nullptr){
                                  current.parent->row = p.row;
                                  current.parent->col = p.col;
                                  q.push(current);
                                  std::pair<int,int> c = std::pair<int, int>(p.row,p.col+1);
                                  std::pair<int,int> parent = std::pair<int, int>(current.parent->row, current.parent->col);
                                  mymap.insert(std::pair<std::pair<int,int>,std::pair<int,int>>(c, parent));
                   }
                   //q.push(QItem(p.row, p.col + 1, p.row, p.col));
                   visited[p.row][p.col + 1] = true;
               }
           }

          //findPathFromMap(mymap, 10, 23, 16, 16); //LINE GIVING LINKER ERROR


           //this->mypath;
           //std::vector<std::pair<int,int>> mypath;
           int target_x = 16;
           int target_y =16;
           int source_x = 10;
           int source_y = 23;

           //Store target pair
           this->mypath.push_back({target_x, target_y});

           //Store parents of target pair


           int key_x=target_x;
           int key_y=target_y;

           //find parents of current nodes and store in the vector

                   while(!(key_x==source_x && key_y == source_y)){
                      // std::cout<< "key_x: " << key_x << "key y: " << key_y << std::endl; //DEBUG
                       std::pair<int,int> p = mymap.find({key_x,key_y})->second;
                       this->mypath.push_back(p);
                      // std::cout<< "parent_x: " << p.first << "parent y: " << p.second << std::endl; DEBUG
                       key_x = p.first;
                       key_y = p.second;
                   }

                   this->mypath.push_back({source_x, source_y});

           //reverse vector to get path right way round
                   std::reverse(this->mypath.begin(),this->mypath.end());

//                   for(size_t i=0; i<mypath.size(); i++){
//                      std::cout<<"row: " << mypath[i].first << " y: " << mypath[i].second << std::endl; //DEBUG
//                   }


//iterate through reversed vector and each time the timer is called set the position of the zombie to position







           //this->findPathFromMap(std::map<std::pair<int,int>,std::pair<int,int>);
           return;
       }


void Zombie::setDir(char c){
    direction = c;
}


void Zombie::moveToGene(){


    //transform coords into XY plane
    //update zombie position on XY PLane
    //send back a single shot timer

    double X = (mypath[this->k].first*20);
    double Y = (mypath[this->k].second*20);
    this->k = this->k+1;

    this->setPos(X, Y);

    if(this->k < this->mypath.size()){
        this->timer->singleShot(1000,this,SLOT(moveToGene()));
    }


}


double Zombie::zombieMapToXY(double coord){return coord*20;}