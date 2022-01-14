let nodes=[ {id:0,parent:undefined},
            {id:1,parent:0},
            {id:2,parent:1},
            {id:4,parent:2},
            {id:3,parent: 2},
            {id:6,parent:3},
            {id:5,parent:4},
            {id:7,parent:6}];

console.table(nodes);

let tobeRemovedIndex=4;
let tobeRemoved=[];

var findAllChildren = function(tree,_nodes){
    let collection=[];
    (Array.isArray(_nodes)? _nodes : [_nodes]).forEach(function(node) {
        let _children = (tree.filter(function(treeNode){
            return node.id === treeNode.parent;
        }));
        if(0 < _children.length){
            collection = collection.concat(_children);
            collection = collection.concat(findAllChildren(tree,_children));
        }
    });
    return collection;
};

let node=nodes[tobeRemovedIndex];

tobeRemoved = findAllChildren(nodes,node);
console.log("final collection to be Removed: ",tobeRemoved.concat(node));
console.log("final collection persisted: ",nodes.filter(function(_node){ return !(tobeRemoved.includes(_node)|| node.id=== _node.id);}));