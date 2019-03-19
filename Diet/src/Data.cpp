#include "Data.h"
#include <stdlib.h>

void Data::readData(char* filePath)
{
   FILE* f = fopen(filePath, "r");

   if(!f)
   {
      printf("Problem while reading instance.\n");
      exit(1);
   }

   if(fscanf(f, "%d", &n_items) != 1)
   {
      printf("Problem while reading instance.\n");
      exit(1);
   }

   //reading carb
   carb = std::vector<double>(n_items, 0);
   for(int i = 0; i < n_items; i++)
   {
      if(fscanf(f, "%lf", &carb[i]) != 1)
      {
	 printf("Problem while reading instance.\n");
	 exit(0);
      }
   }

   //reading prot
   prot = std::vector<double>(n_items, 0);
   for(int i = 0; i < n_items; i++)
   {
      if(fscanf(f, "%lf", &prot[i]) != 1)
      {
	 printf("Problem while reading instance.\n");
	 exit(0);
      }
   }

   //reading fat
   fat = std::vector<double>(n_items, 0);
   for(int i = 0; i < n_items; i++)
   {
      if(fscanf(f, "%lf", &fat[i]) != 1)
      {
	 printf("Problem while reading instance.\n");
	 exit(0);
      }
   }

   //reading cost
   cost = std::vector<double>(n_items, 0);
   for(int i = 0; i < n_items; i++)
   {
      if(fscanf(f, "%lf", &cost[i]) != 1)
      {
	 printf("Problem while reading instance.\n");
	 exit(0);
      }
   }
}

int Data::getNItems()
{
   return n_items;
}

double Data::getCarb(unsigned int indexC)
{
   if(indexC >= n_items)
   {
      return 0;
   }

   return carb[indexC]; 
}

double Data::getProt(unsigned int indexP)
{
   if(indexP >= n_items)
   {
      return 0;
   }

   return prot[indexP]; 
}

double Data::getFat(unsigned int indexF)
{
   if(indexF >= n_items)
   {
      return 0;
   }

   return fat[indexF]; 
}

double Data::getCost(unsigned int indexCo)
{
   if(indexCo >= n_items)
   {
      return 0;
   }

   return cost[indexCo]; 
}
