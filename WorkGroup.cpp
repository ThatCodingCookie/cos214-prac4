#include <iostream>

#include "WorkGroup.h"
#include "DepthFirstIterator.h"
#include "PendingInspectionIterator.h"


WorkGroup::WorkGroup(const std::string& name) : WorkComponent(name) {}

void WorkGroup::add(WorkComponent* component) {
    children.push_back(component);
}

void WorkGroup::remove(WorkComponent* component) {

    if (children.empty()) {
        std::cout << "No Tasks" << std::endl;
        return;
    }

    // goes through each position in observers to find and remove the component
    for (auto it = children.begin(); it != children.end(); ++it) {
        if (*it == component) {
            children.erase(it);
            return;
        }
    }
}

double WorkGroup::getCost() const {
    double total = 0;
    for (const auto& child : children) {
        total += child->getCost();
    }
    return total;
}

int WorkGroup::getDuration() const {
    int maxDuration = 0;
    for (const auto& child : children) {
        int duration = child->getDuration();
        if (duration > maxDuration) {
            maxDuration = duration;
        }
    }
    return maxDuration;
}
void WorkGroup::describe(int depth) const {
    std::cout << std::string(depth, ' ') << name << std::endl;
    for (const auto& child : children) {
        child->describe(depth + 1);
    }
}
WorkIterator* WorkGroup::createFullIterator() const {
    return new DepthFirstIterator(this);
}
WorkIterator* WorkGroup::createPendingInspectionIterator() const {
    return new PendingInspectionIterator(this);
}


WorkGroup::~WorkGroup() {
    for (auto& child : children) {
        delete child;
    }
}