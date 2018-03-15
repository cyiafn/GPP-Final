#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <initializer_list>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "platform.h"
#include "constants.h"
#include "audio.h"

class Characters;

class BehaviourTree
{
	public:


		class Node {  // This class represents each node in the behaviour tree.
			public:
				virtual bool run() = 0;
		};
		
		class CompositeNode : public Node {  //  This type of Node follows the Composite Pattern, containing a list of other Nodes.
			private:
				std::vector<Node*> children;
			public:
				const std::vector<Node*>& getChildren() const {return children;}
				void addChild (Node* child) {children.emplace_back(child);}
				void addChildren (std::initializer_list<Node*>&& newChildren) {for (Node* child : newChildren) addChild(child);}
				template <typename CONTAINER>
				void addChildren (const CONTAINER& newChildren) {for (Node* child : newChildren) addChild(child);}
			protected:
				std::vector<Node*> childrenShuffled() const {std::vector<Node*> temp = children;  std::random_shuffle (temp.begin(), temp.end());  return temp;}
		};
		

		//class Selector : public CompositeNode {
		//	public:
		//		virtual bool run() override {
		//			for (Node* child : getChildren()) {  // The generic Selector implementation
		//				if (child->run())  // If one child succeeds, the entire operation run() succeeds.  Failure only results if all children fail.
		//					return true;
		//			}
		//			return false;  // All children failed so the entire run() operation fails.
		//		}

		//};


		class Sequence : public CompositeNode {
			public:
				virtual bool run() override {
					for (Node* child : getChildren()) {  // The generic Sequence implementation.
						if (!child->run())  // If one child fails, then enter operation run() fails.  Success only results if all children succeed.
							return false;
					}
					return true;  // All children suceeded, so the entire run() operation succeeds.
				}
		};


		class Root : public Node {
			private:
				Node* child;
				friend class BehaviourTree;
				void setChild (Node* newChild) {child = newChild;}
				virtual bool run() override {return child->run();}
		};


		//Types of Behaviors (Escape (Branch into Side of Walls and general running away) , Fighting, Picking up Items)
		class MainSelector : public CompositeNode {
		private:
			Characters* chars;
			std::vector<Platform*> platforms;
		public:
			MainSelector(Characters* chars, std::vector<Platform*> platforms) { this->chars = chars; this->platforms = platforms; }
			virtual bool run() override {
				bool platformBelow = false;
				for (std::vector<int>::size_type i = 0; i != platforms.size(); i++) {
					if (chars->getX() + charactersNS::WIDTH/2 * chars->getScale() <= platforms[i]->getX() + platformNS::WIDTH* platforms[i]->getScale() && chars->getX() + charactersNS::WIDTH / 2 * chars->getScale()>= platforms[i]->getX() && chars->getY() + charactersNS::HEIGHT * chars->getScale() <= platforms[i]->getY() )
					{
						platformBelow = true;
					}
					else
					{

					}
				}
				if (platformBelow == false)
				{
					return getChildren()[1]->run();
				}
				else if (chars->getHealthComponent()->getPerc() > 150)
				{
					return getChildren()[2]->run();
				}
				else
				{
					return getChildren()[2]->run();
				}
			}
		};

		class attackSelector : public CompositeNode {
		private:
			Characters * chars;
			std::vector<Platform*> platforms;
			std::vector<Characters*> characters;
			Game* cipher;
		public:
			attackSelector(Characters* chars, std::vector<Platform*> platforms, Game* cip, std::vector<Characters*> characters) { this->chars = chars; this->platforms = platforms; this->cipher = cip;  this->characters = characters; }
			virtual bool run() override {
				Characters* nearestChar;
				float distanceToNearestChar = GAME_WIDTH * GAME_HEIGHT;
				bool targettedPlayer = true;
				for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
					if (characters[i] != chars)
					{
						float dispX = characters[i]->getX() - chars->getX();
						float dispY = characters[i]->getY() - chars->getY();
						float dist = sqrt(dispX * dispX + dispY * dispY);
						if (dist < distanceToNearestChar)
						{
							nearestChar = characters[i];
							distanceToNearestChar = dist;
						}
					}
				}
				if (nearestChar->getY() >= chars->getY() + charactersNS::MAX_JUMP/2 || nearestChar->getY() <= chars->getY() - charactersNS::MAX_JUMP / 2)
				{
					targettedPlayer = false;
				}
				if (targettedPlayer == false)
				{
					return getChildren()[0]->run();
				}
				else
				{
					return getChildren()[1]->run();
				}
			}
		};

		class navigateToNearestPlayer : public Node {
		private:
			Characters * chars;
			std::vector<Platform*> platforms;
			std::vector<Characters*> characters;
			Game* cipher;
		public:
			navigateToNearestPlayer(Characters* chars, std::vector<Platform*> platforms, Game* cip, std::vector<Characters*> characters) { this->chars = chars; this->platforms = platforms; this->cipher = cip;  this->characters = characters; }
			virtual bool run() override {
				Characters* targetedCharacter;
				float lowestTotalDis = 0;
				float totalDistance = 0;
				for (std::vector<int>::size_type z = 0; z != characters.size(); z++)
				{
					if (characters[z] != chars)
					{
						float xDis = characters[z]->getX() - chars->getX();
						float yDis = characters[z]->getY() - chars->getY();
						totalDistance = sqrt(yDis * yDis + xDis * xDis);
						if (lowestTotalDis == 0)
						{
							targetedCharacter = characters[z];
							lowestTotalDis = totalDistance;
						}
						else
						{
							if (lowestTotalDis > totalDistance)
							{
								targetedCharacter = characters[z];
								lowestTotalDis = totalDistance;
							}
						}
					}
					
				}
				chars->setTargetedPlayer(targetedCharacter);
				float displacementX = (targetedCharacter->getX()) - (chars->getX() + charactersNS::WIDTH / 2 * chars->getScale());
				float displacementY = targetedCharacter->getY() - (chars->getY() - charactersNS::HEIGHT * chars->getScale());
				float distanceX = displacementX;
				if (distanceX < 0)
					distanceX *= -1;
				float distanceY = displacementY;
				if (distanceY < 0)
					distanceY *= -1;
				if (chars->getMoveComponent()->getVelocity().y > 0)
				{
					if (chars->getJumpCounter() != 2)
					{
						chars->jump();
					}
				}
				if (targetedCharacter->getY() <= chars->getY() - charactersNS::MAX_JUMP / 2)
				{
					if (!(chars->getX() + 50 >= targetedCharacter->getX()) && !(chars->getX() - 50 <= targetedCharacter->getX()))
					{
 						if (targetedCharacter->getX() - chars->getX() < 0)
						{
							chars->moveLeft();
						}
						else
						{
							chars->moveRight();
						}
					}
					else
					{
						if (chars->getMoveComponent()->getVelocity().y >= 0)
						{
							if (chars->getJumpCounter() != 2)
							{
								chars->jump();
							}
						}
					}
						
				}
				else if (targetedCharacter->getY() >= chars->getY() + charactersNS::MAX_JUMP / 2)
				{
					if (!(chars->getX() + 50 >= targetedCharacter->getX()) && !(chars->getX() - 50 <= targetedCharacter->getX()))
					{
						if (targetedCharacter->getX() - chars->getX() < 0)
						{
							chars->moveLeft();
						}
						else
						{
							chars->moveRight();
						}
					}
					else
					{
							chars->drop();
					}
					
				}
				return true;
			}
		};


		class fightPlayer : public Node {
		private:
			Characters * chars;
			std::vector<Platform*> platforms;
			std::vector<Characters*> characters;
			Game* cipher;
			Audio *audio;
		public:
			fightPlayer(Characters* chars, std::vector<Platform*> platforms, Game* cip, std::vector<Characters*> characters, Audio *au) { this->chars = chars; this->platforms = platforms; this->cipher = cip;  this->characters = characters; this->audio = au; }
			virtual bool run() override {
				Characters* targetedCharacter;
				float lowestTotalDis = 0;
				float totalDistance = 0;
				for (std::vector<int>::size_type z = 0; z != characters.size(); z++)
				{
					if (characters[z] != chars)
					{
						float xDis = characters[z]->getX() - chars->getX();
						float yDis = characters[z]->getY() - chars->getY();
						if (xDis < 0)
							xDis *= -1;
						if (yDis < 0)
							yDis *= -1;
						totalDistance = sqrt(xDis * xDis + yDis * yDis);
						if (lowestTotalDis == 0)
						{
							targetedCharacter = characters[z];
							lowestTotalDis = totalDistance;
						}
						else
						{
							if (lowestTotalDis > totalDistance)
							{
								targetedCharacter = characters[z];
								lowestTotalDis = totalDistance;
							}
						}
					}

				}
				chars->setTargetedPlayer(targetedCharacter);
				if (chars->getX() <= chars->getTargetedPlayer()->getX())
				{
					chars->setFacingRight(true);
				}
				else
				{
					chars->setFacingRight(false);
				}
				float distance = chars->getX() - chars->getTargetedPlayer()->getX();
				if (distance < 0)
					distance *= -1;
				if (chars->getFacingRight() == true && distance > 70)
				{
					chars->moveRight();
					if (chars->getQCD() == false)
					{
						chars->useQ(chars->getFacingRight(), *chars->getCenter(), cipher);
						audio->playCue(GUN_SHOT);
					}
					if (chars->getWCD() == false)
					{
						chars->useW(chars->getFacingRight(), *chars->getCenter(), cipher);
						audio->playCue(GUN_SHOT);
					}
				}
				else if (chars->getFacingRight() == false && distance > 70)
				{
					chars->moveLeft();
					if (chars->getQCD() == false)
					{
						chars->useQ(chars->getFacingRight(), *chars->getCenter(), cipher);
						audio->playCue(GUN_SHOT);
					}
					if (chars->getWCD() == false)
					{
						chars->useW(chars->getFacingRight(), *chars->getCenter(), cipher);
						audio->playCue(GUN_SHOT);
					}
				}
				return true;
			}
		};


		class jumpToNearestPlatform : public Node {
		private:
			Characters* chars;
			std::vector<Platform*> platforms;
		public:
			jumpToNearestPlatform(Characters* chars, std::vector<Platform*> platforms) { this->chars = chars; this->platforms = platforms; }
			virtual bool run() override {
				int indexOfMostPreferrablePlatform;
				float distanceToClosestPlatform = GAME_WIDTH * GAME_HEIGHT;
				float currentCharX = chars->getX() + charactersNS::WIDTH/2 * chars->getScale();
				float currentCharY = chars->getY() + charactersNS::HEIGHT / 2 * chars->getScale();
				for (std::vector<int>::size_type i = 0; i != platforms.size(); i++) {
					float disX = currentCharX - (platforms[i]->getX() + platformNS::WIDTH * platforms[i]->getScale() / 2 );
					if (disX < 0)
						disX *= -1;
					float disY = currentCharY - (platforms[i]->getY() + platformNS::HEIGHT * platforms[i]->getScale() / 2);
					if (disY < 0)
						disX *= -1;
					float totalDist = sqrt(disX * disX + disY * disY);
					if (totalDist < distanceToClosestPlatform)
					{
						distanceToClosestPlatform = totalDist;
						indexOfMostPreferrablePlatform = i;
					}
				}
				if (platforms[indexOfMostPreferrablePlatform]->getX() + 300 > chars->getX())
				{
					chars->moveRight();
				}
				else if (platforms[indexOfMostPreferrablePlatform]->getY() - 300 < chars->getX())
				{
					chars->moveLeft();
				}

				if (!(chars->getJumpCounter() >= 2) && chars->getMoveComponent()->getVelocity().y >= 0)
				{
					if (chars->getJumpCounter() < 2)
					{
						chars->jump();
					}
				}
				return true;
			}
			
		};

		class escapePlayers : public Node {
		private:
			Characters * chars;
			std::vector<Platform*> platforms;
			std::vector<Characters*> characters;
			Game* cipher;
		public:
			escapePlayers(Characters* chars, std::vector<Platform*> platforms, Game* cip, std::vector<Characters*> characters) { this->chars = chars; this->platforms = platforms; this->cipher = cip;  this->characters = characters; }
			virtual bool run() override {
				Platform* targetedPlatform;
				float highestTotalDis = 0;
				for (std::vector<int>::size_type i = 0; i != platforms.size(); i++) {
					float totalDistance = 0;
					for (std::vector<int>::size_type z = 0; z != characters.size(); z++)
					{
						float xDis = characters[z]->getX() - platforms[i]->getX();
						float yDis = characters[z]->getY() - platforms[i]->getY();
						if (xDis < 0)
							xDis *= -1;
						if (yDis < 0)
							yDis *= -1;
						totalDistance += sqrt(xDis * xDis + yDis * yDis);
					}
					if (targetedPlatform == NULL)
					{
						targetedPlatform = platforms[i];
						highestTotalDis = totalDistance;
					}
					else
					{
						if (highestTotalDis < totalDistance)
						{
							targetedPlatform = platforms[i];
							highestTotalDis = totalDistance;
						}
					}
				}
				float displacementX = targetedPlatform->getX() - chars->getX();
				float displacementY = targetedPlatform->getY() - chars->getY();
				float distanceX = displacementX;
				if (distanceX < 0)
					distanceX *= -1;
				float distanceY = displacementY;
				if (distanceY < 0)
					distanceY *= -1;
				if (distanceY > charactersNS::MAX_JUMP && displacementY < 0)
				{
					Platform* transitionPlatform;
					float lowestTotalDisX = GAME_WIDTH * GAME_HEIGHT;
					for (std::vector<int>::size_type i = 0; i != platforms.size(); i++) {
						if (platforms[i]->getY() > targetedPlatform->getY() && platforms[i]->getY() < chars->getY())
						{
							float tempDisX = platforms[i]->getX() - targetedPlatform->getX();
							if (tempDisX < 0)
								tempDisX *= -1;
							if (tempDisX < lowestTotalDisX)
							{
								transitionPlatform = platforms[i];
								lowestTotalDisX = tempDisX;
							}
						}

					}
					if (!(chars->getX() + 50 <= transitionPlatform->getX()) && !(chars->getX() - 50 >= transitionPlatform->getX()))
					{
						if (transitionPlatform->getX() - chars->getX() < 0)
						{
							chars->moveLeft();
						}
						else
						{
							chars->moveRight();
						}
					}
					else
					{
						if (chars->getMoveComponent()->getVelocity().y <= 0)
						{
							if (chars->getJumpCounter() < 2)
							{
								{
									chars->jump();
								}
							}
						}
					}
				}
				else if (displacementY < 0)
				{
					if (!(chars->getX() + 50 <= targetedPlatform->getX()) && !(chars->getX() - 50 >= targetedPlatform->getX()))
					{
						if (targetedPlatform->getX() - chars->getX() < 0)
						{
							chars->moveLeft();
						}
						else
						{
							chars->moveRight();
						}
					}
					else
					{
						if (chars->getMoveComponent()->getVelocity().y <= 0)
						{
							if (chars->getJumpCounter() < 2)
							{
								chars->jump();
							}
							
						}
					}
				}
				else if (displacementY > 0)
				{
					if (!(chars->getX() + 50 <= targetedPlatform->getX()) && !(chars->getX() - 50 >= targetedPlatform->getX()))
					{
						if (targetedPlatform->getX() - chars->getX() < 0)
						{
							chars->moveLeft();
						}
						else
						{
							chars->moveRight();
						}
					}
					else
					{
						if (chars->getY() < targetedPlatform->getY() - 10)
						{
							chars->drop();
						}
					}
				}
				return true;
			}
		};

	private:
		Root* root;
	public:
		//BehaviourTree() : root(new Root) {}
		BehaviourTree() { root = new Root(); }
		void setRootChild (Node* rootChild) const {root->setChild (rootChild);}
		bool run() const {return root->run();}
};