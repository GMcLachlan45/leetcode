#include <iostream>
#include <vector>
#include <limits>

/*int minimumCostToPaintHousesOptimized(std::vector<std::vector<int>> costs) {
  int lastMin = 0;
  int lastCol = -1;
  int lastSecondMin = 0;
  int lastSecondCol = -1;

  for(std::vector<int> houseCosts : costs) {
  int min = 0;
  int col = 0;
  int secondMin = 0;
  int secondCol = 0;
  // To shorten
  if(houseCosts[0] < houseCosts[1]) {
  min = houseCosts[0];
  col = 0;
  secondMin = houseCosts[1];
  secondCol = 1;
  } else if(houseCosts[0] > houseCosts[1]) {
  min = houseCosts[1];
  col = 1;
  secondMin = houseCosts[0];
  secondCol = 0;
  } else {
  min = houseCosts[0];
  col = -1;
  secondMin = houseCosts[0];
  secondCol = -1;
  }

  for(int i = 2; i < houseCosts.size(); i++) {
  if(houseCosts[i) < min) {
  secondMin = min;
  min = houseCosts[i];
  secondCol = col;
  col = i;
  } else if (houseCosts[i] == min)
  col = -1;
  else if(houseCosts[i] < secondMin) {
  secondMin = houseCosts[i];
  secondCol = i;
  } else if(houseCosts[i] == secondMin)
  secondCol = -1;
  }


  lastMin = min;
  lastCol = col;
  lastSecondMin = secondMin;
  lastSecondCol = secondCol;
  }

  return lastMin;
  }*/


int minimumCostToPaintHouses(std::vector<std::vector<int>> costs) {
    // Keep a cost of the prices that assume the last neighbor wasnt color i
    std::vector<int> prices(costs[0].size());
    for(std::vector<int> houseCosts : costs) {
        std::vector<int> nextPrices(costs[0].size(), std::numeric_limits<int>::max());
        for(int i = 0; i < houseCosts.size(); i++) {
            for(int j = 0; j < houseCosts.size(); j++) {
                if(i == j)
                    continue;
                if(prices[j] + houseCosts[i] < nextPrices[i])
                    nextPrices[i] = prices[j] + houseCosts[i];
            }

        }
        prices=nextPrices;
    }
    int ans = prices[0];
    for(int x : prices)
        if(x < ans)
            ans = x;
    return ans;
}


int main() {
    std::vector<std::vector<int>> input = {
        {14, 20, 16, 13},
        {15, 6, 10, 4},
        {10, 8, 12, 11}
    };
    std::cout << "The minimum cost to paint each house given the following costs per color per house "<<std::endl;

    for(int i = 0; i < input.size(); i++) {
        std::cout<<i<<"\t";
        for(int x : input[i])
            std::cout<<x<<"\t";
        std::cout << std::endl;
    }
    std::cout << "is " << minimumCostToPaintHouses(input)<<std::endl;

    input = {
        {1,1},
        {1,1},
        {100000,1}
    };
    std::cout << "The minimum cost to paint each house given the following costs per color per house "<<std::endl;

    for(int i = 0; i < input.size(); i++) {
        std::cout<<i<<"\t";
        for(int x : input[i])
            std::cout<<x<<"\t";
        std::cout << std::endl;
    }
    std::cout << "is " << minimumCostToPaintHouses(input)<<std::endl;

}
