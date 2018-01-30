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
#include "characters.h"
#include "map.h"
#include "platform.h"


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
		
		class Selector : public CompositeNode {
			public:
				virtual bool run() override {
					for (Node* child : getChildren()) {  // The generic Selector implementation
						if (child->run())  // If one child succeeds, the entire operation run() succeeds.  Failure only results if all children fail.
							return true;
					}
					return false;  // All children failed so the entire run() operation fails.
				}

		};

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
		class checkIfFallingEdge : public Node {
		private:
			Characters* chars;
			std::vector<Platform*> platforms;
		public:
			checkIfFallingEdge(Characters* chars, std::vector<Platform*> platforms) { this->chars = chars; this->platforms = platforms; }
			virtual bool run() override {
				for (std::vector<int>::size_type i = 0; i != platforms.size(); i++) {
					if (((chars->getX() + charactersNS::WIDTH + 1 == platforms[i]->getX()) || chars->getX() + charactersNS::WIDTH == platforms[i]->getX()) && ((chars->getY() + charactersNS::HEIGHT != platforms[i]->getY() + platformNS::floorCoords) || chars->getY() + charactersNS::HEIGHT != platforms[i]->getY() + platformNS::floorCoords - 1) )
					{
						return true;
					}
					else if (((chars->getX() == platforms[i]->getX() + platformNS::WIDTH) || chars->getX() + 1 == platforms[i]->getX() + platformNS::WIDTH) && ((chars->getY() + charactersNS::HEIGHT != platforms[i]->getY() + platformNS::floorCoords) || chars->getY() + charactersNS::HEIGHT != platforms[i]->getY() + platformNS::floorCoords - 1))
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		};

		class jumpFallingEdge : public Node {
		private:
			Characters * chars;
			std::vector<Platform*> platforms;
		public:
			jumpFallingEdge(Characters* chars, std::vector<Platform*> platforms) { this->chars = chars; this->platforms = platforms; }
			virtual bool run() override {
				if (chars->getMoveComponent()->getVelocity().y != 0)
				{
					return false;
				}
				else
				{
					VECTOR2 vel;
					vel.x = 0;
					vel.y = 200;
					chars->getMoveComponent()->setVelocity(vel);
					return true;
				}
			}
		};

		class checkIfPlatformBelow : public Node {
		private:
			Characters * chars;
			std::vector<Platform*> platforms;
		public:
			checkIfPlatformBelow(Characters* chars, std::vector<Platform*> platforms) { this->chars = chars; this->platforms = platforms; }
			virtual bool run() override {
				for (std::vector<int>::size_type i = 0; i != platforms.size(); i++) {
					if (chars->getMoveComponent->getVelocity().y >= 0 && ((chars->getY() + charactersNS::HEIGHT != platforms[i]->getY() + platformNS::floorCoords) || chars->getY() + charactersNS::HEIGHT != platforms[i]->getY() + platformNS::floorCoords - 1))
					{
						return false;
					}
					else
					{
						return true;
					}
				}
			}
		};


	private:
		Root* root;
	public:
		BehaviourTree() : root(new Root) {}
		void setRootChild (Node* rootChild) const {root->setChild (rootChild);}
		bool run() const {return root->run();}
};