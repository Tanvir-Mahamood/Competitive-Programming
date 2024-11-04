// Header files

#include<ext/pb_ds/assoc_container.hpp> // include external policy based data structured
#include<ext/pb_ds/tree_policy.hpp> // contains tree policy that will be used
// Including tree_order_statistics_node_update

using namespace __gnu_pbds;

// Declaration of tree-based container
template<
    // key type
    typename key,

    // mapped-policy
    typename Mapped,

    // key comparison functor
    typename Cmp_Fn = std::less<key>,

    // specifies which underlying data structures to use
    typename tag = rb_tree_tag,

    template<
        typename Const_Node_Iterator,
        typename Node_Iterator,
        typename Cmp_Fn_,
        typename Allocator_>

        // a policy for updating node invariant
        class Node_Update = null_node_update,

        // an allocator typedef
        typename Allocator = std::allocator<char> >
class tree;

// int = data type of key, null_type = if map policy is null typed => work like set, less<int> = it knows how to compare 2 keyes
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set

Tree Structures
rb_tree_tag    (red - black tree)
splay_tree_tag (splay tree)
ov_tree_tag    (ordered - vector tree)

Final Declaration that we will use

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

setting it in windows
\MinGW\lib\gcc\mingw32\6.3.0\include\c++\ext\pb_ds\detail\hash_standard_resize_policy_imp.hpp

