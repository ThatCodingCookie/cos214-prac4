Lucian van der Merwe u25054262 
Conrad Botha u25017749 
Nontokozo Madela u25677404

Things to know: Hierarchy: Project->Phase->Zone->Task 2 traversals: full depth first and "pending inspection" Iterator that filters by state+decoration Decorators wrap WorkComponent

# TaskForge

TaskForge is a C++ construction project management system for COS 214 Practical 4.

## Design Patterns

- **Composite:** `WorkComponent`, `WorkGroup`, `Task`
- **Iterator:** `DepthFirstIterator`, `PendingInspectionIterator`
- **State:** Planned, In Progress, Blocked, Completed
- **Decorator:** Safety Inspection, Permit Compliance, Subcontractor

## Docker

Build the image:

docker build -t taskforge .

Run the application:

docker run --rm taskforge


## Valgrind

docker run --rm taskforge valgrind --leak-check=full --show-leak-kinds=all ./taskforge


## GDB

docker run --rm -it --cap-add=SYS_PTRACE --security-opt seccomp=unconfined taskforge gdb ./taskforge

Example:

text to use:
    break Task::start
    run
    next
    continue
    quit


## Local Build

make
./taskforge

Clean:
make clean

## Documentation

UML diagrams and design documentation are located in the `docs/` directory.