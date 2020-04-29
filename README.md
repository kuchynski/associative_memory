This algorithm provide quick access to the struct data pointer.
The basic idea is to compare each string key symbol only once. It reduces time access even if there are a lot of elements into the memory.

For a example if we need to storage three notice about famous people, the final structure is:

![Image description](./pic.png)

Where <span style="color:blue">p</span> is a valid data pointer, <span style="color:gray">p A B ... Z</span> are unused pointers.