//����ѵ������ֵ�㷨
#include <iostream>
#include <random>
#include "../Game/Game.h"
using namespace std;


void main_test2()
{
  random_device rd;
  auto rand = mt19937_64(rd());

  Game game;
  //int cards[6] = { 1,2,3,6,11,10 };
  int cards[6] = { 1,2,3,4,5,6 };
  int zhongmaBlue[5] = { 18,0,0,0,0 };
  game.newGame(rand, 1, cards, zhongmaBlue);
  game.motivation = 5;
  for (int i = 0; i < 6; i++)
    game.cardJiBan[i] = 100;
  game.turn = 70;
  for(int i=0;i<5;i++)
    game.trainLevelCount[i] = 1000;
  //game.venusAvailableWisdom = 3;
  //game.venusIsWisdomActive = true;
  int AllGenCards[6] = { 4,5,7,8,9,13 };
  for (int g = 0; g < 6; g++)
  {
    int gen = AllGenCards[g];
    game.cardId[4] = gen;
    int N = 1000000;
    double total = 0;
    for (int i = 0; i < N; i++)
    {
      game.randomDistributeCards(rand);
      game.calculateTrainingValue();
      double bestv = -100;
      for (int t = 0; t < 5; t++)
      {
        double totalv = 0;
        for (int v = 0; v < 5; v++)
        {
          totalv += game.trainValue[t][v];
        }
        totalv = totalv + 0.4 * game.trainValue[t][5] + 1.5 * game.trainValue[t][6];
        if (totalv > bestv)bestv = totalv;
      }
      total += bestv;
    }
    cout <<GameDatabase::AllSupportCardNames[gen]<<": "<< total / N << endl;
  }

  game.cardId[4] = 4;//��������������ӳ�
  for (int yq = 0; yq <= 100; yq+=10)
  {
    GameDatabase::AllSupportCards[4].youQingBasic = yq;
    int N = 300000;
    double total = 0;
    for (int i = 0; i < N; i++)
    {
      game.randomDistributeCards(rand);
      game.calculateTrainingValue();
      double bestv = -100;
      for (int t = 0; t < 5; t++)
      {
        double totalv = 0;
        for (int v = 0; v < 5; v++)
        {
          totalv += game.trainValue[t][v];
        }
        totalv = totalv + 0.4 * game.trainValue[t][5] + 1.5 * game.trainValue[t][6];
        if (totalv > bestv)bestv = totalv;
      }
      total += bestv;
    }
    cout << "����="<<yq << ": " << total / N << endl;
  }
  GameDatabase::AllSupportCards[4].youQingBasic = 32;

  for (int d = 0; d <= 100; d += 10)
  {
    GameDatabase::AllSupportCards[4].deYiLv=d;
    int N = 300000;
    double total = 0;
    for (int i = 0; i < N; i++)
    {
      game.randomDistributeCards(rand);
      game.calculateTrainingValue();
      double bestv = -100;
      for (int t = 0; t < 5; t++)
      {
        double totalv = 0;
        for (int v = 0; v < 5; v++)
        {
          totalv += game.trainValue[t][v];
        }
        totalv = totalv + 0.4 * game.trainValue[t][5] + 1.5 * game.trainValue[t][6];
        if (totalv > bestv)bestv = totalv;
      }
      total += bestv;
    }
    cout << "������=" << d << ": " << total / N << endl;
  }

  GameDatabase::AllSupportCards[4].deYiLv = 50;

  for (int d = 0; d <= 100; d += 10)
  {
    GameDatabase::AllSupportCards[2].deYiLv = d;
    int N = 300000;
    double total = 0;
    for (int i = 0; i < N; i++)
    {
      game.randomDistributeCards(rand);
      game.calculateTrainingValue();
      double bestv = -100;
      for (int t = 0; t < 5; t++)
      {
        double totalv = 0;
        for (int v = 0; v < 5; v++)
        {
          totalv += game.trainValue[t][v];
        }
        totalv = totalv + 0.4 * game.trainValue[t][5] + 1.5 * game.trainValue[t][6];
        if (totalv > bestv)bestv = totalv;
      }
      total += bestv;
    }
    cout << "�߷������=" << d << ": " << total / N << endl;
  }

  GameDatabase::AllSupportCards[2].deYiLv = 50;

  for (int d = 0; d <= 20; d += 2)
  {
    GameDatabase::AllSupportCards[4].xunLianBasic = d;
    int N = 300000;
    double total = 0;
    for (int i = 0; i < N; i++)
    {
      game.randomDistributeCards(rand);
      game.calculateTrainingValue();
      double bestv = -100;
      for (int t = 0; t < 5; t++)
      {
        double totalv = 0;
        for (int v = 0; v < 5; v++)
        {
          totalv += game.trainValue[t][v];
        }
        totalv = totalv + 0.4 * game.trainValue[t][5] + 1.5 * game.trainValue[t][6];
        if (totalv > bestv)bestv = totalv;
      }
      total += bestv;
    }
    cout << "ѵ���ӳ�=" << d << ": " << total / N << endl;
  }
}