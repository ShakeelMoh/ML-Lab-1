//ML lab1 K means clustering
//Shakeel Mohamed

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cmath>

using namespace std;

bool done = false;//Boolean to check if program finished

//Compute new centroid for each point
void computeCentroids(vector<int*> points, vector<float*> centroids){
   
   int checker = 0; //If checker == 3 it means all 3 centroids are the same as before thus we can stop.
   for (int i = 0; i < centroids.size(); ++i){//Iterates 3 times
      int xTotal = 0;
      int yTotal = 0;
      int numPts = 0;
      for (int j = 0; j < points.size(); ++j){//Iterates how many points in cluster x  
         if (points[j][2] == (i+1)){
            xTotal += points[j][0];
            yTotal += points[j][1];
            numPts ++;
            
         }
      }
      //cout << "X total: " << xTotal << ": Y total: " << yTotal << " - " << numPts << endl;
      
      float newCentroidx = (float)xTotal/(float)numPts;
      float newCentroidy = (float)yTotal/(float)numPts;
      
      //Check if centroid is same as prev calculated one
      if (newCentroidx == centroids[i][0] && newCentroidy == centroids[i][1]){
         checker++;
         if (checker == 3){
            cout << "Centroids the same. Stop algorithm" << endl;
            done = true;
         }
      }
      
      centroids[i][0] = newCentroidx;
      centroids[i][1] = newCentroidy;
      //cout << "New centroid " << (i+1) << " is (" << centroids[i][0] << "," << centroids[i][1] << ")" << endl;
   }
}

//Loop for each point in dataset. Compute which cluster each point belongs to
void computeClusters(vector<int*> points, vector<float*> centroids) {
   
   cout << "Centroid 1: (" << centroids[0][0] << "," << centroids[0][1] << ")" << endl;
   cout << "Centroid 2: (" << centroids[1][0] << "," << centroids[1][1] << ")" << endl;
   cout << "Centroid 3: (" << centroids[2][0] << "," << centroids[2][1] << ")" << endl;
   
   for (int i = 0; i < points.size(); ++i){
      float shortestDist = 100;//Initialize shortest distance
      int closestCentroid = 0;
      for (int j = 0; j < 3; ++j){
         float dist = sqrt(pow((centroids[j][0] - points[i][0]),2)    +    pow((centroids[j][1] - points[i][1]),2));
         //cout << "Temp distance for point: " << (i+1) << " is: " << dist << "\n";
         if (dist < shortestDist){
            shortestDist = dist;
            closestCentroid = j;
         }
      }
      
      cout << "Shortest dist point: " << (i+1) << " to centroid " << (closestCentroid+1) << " is: " << shortestDist<< endl;
      points[i][2] = closestCentroid + 1;
   }
   
   ofstream outputFile;
   outputFile.open("outputFile.txt", ofstream::app);
   
   //Determine which points are in which clusters
   string printClusters = "Cluster 1: ";
   for(int i = 0; i < points.size(); ++i){
      //cout << points[i][2] << "\n";
      if(points[i][2] == 1){
         printClusters += to_string((i+1)) + " ";
      }
   }
   outputFile << printClusters << endl;
   outputFile << "Centroid (" << centroids[0][0] << "," << centroids[0][1] << ")\n\n";
   
   printClusters = "Cluster 2: ";
   for(int i = 0; i < points.size(); ++i){
      //cout << points[i][2] << "\n";
      if(points[i][2] == 2){
         printClusters += to_string((i+1)) + " ";
      }
   }
   outputFile << printClusters << endl;
   outputFile << "Centroid (" << centroids[1][0] << "," << centroids[1][1] << ")\n\n";

   printClusters = "Cluster 3: ";
   for(int i = 0; i < points.size(); ++i){
      //cout << points[i][2] << "\n";
      if(points[i][2] == 3){
         printClusters += to_string((i+1)) + " ";
      }
   }
   outputFile << printClusters << endl;
   outputFile << "Centroid (" << centroids[2][0] << "," << centroids[2][1] << ")\n\n";
   outputFile.close();
   
   computeCentroids(points, centroids);
   
}

//Main
int main (int argc, char *argv[]) {
   
   cout << "K-means clustering simulator" << endl;
   
   //Create vector to hold points
   vector<int*> points = vector<int*>();
   vector<float*> centroids = vector<float*>();
   int numPoints = 8;
   
   //Specify centroids
   float centroid1[2] = {2,10};
   float centroid2[2] = {5,8};
   float centroid3[2] = {1,2};
   
   centroids.push_back(centroid1);
   centroids.push_back(centroid2);
   centroids.push_back(centroid3);
   
   //Specify all points
   int pt1[3] = {2,10,0};
   int pt2[3] = {2,5,0};
   int pt3[3] = {8,4,0};
   int pt4[3] = {5,8,0};
   int pt5[3] = {7,5,0};
   int pt6[3] = {6,4,0};
   int pt7[3] = {1,2,0};
   int pt8[3] = {4,9,0};
   
   points.push_back(pt1);
   points.push_back(pt2);
   points.push_back(pt3);
   points.push_back(pt4);
   points.push_back(pt5);
   points.push_back(pt6);
   points.push_back(pt7);
   points.push_back(pt8);
   
   cout << "Number of points: " << points.size() << endl;
   int* ptr = points.front();
   //cout << ptr[0];//0 points to 2, 1 points to 10...
   //cout << points[0][0];//Points to 2, [0][1] points to 10...
   
   ofstream outputFile;
   outputFile.open("outputFile.txt");
   outputFile << "K-means Clustering Simulator\n\n";
   outputFile.close();
   
   int iteration = 1;
   
   //Compute clusters until clusters stay the same
   while (!done){
      ofstream outputFile;
      outputFile.open("outputFile.txt", ofstream::app);
      
      outputFile << "Iteration " << iteration << "\n" << endl;
      outputFile.close();
      cout << "\nIteration " << iteration << "\n" << endl;
      computeClusters(points, centroids);
      iteration++;
   }

   return 0;
}


   
