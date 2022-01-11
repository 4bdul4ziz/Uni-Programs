class Node
  attr_accessor :val, :left, :right
  def initialize(val)
    @val = val
    @left, @right = nil, nil
  end
end

root = Node.new(3)
child_l = Node.new(9)
child_r = Node.new(20)
grand_child_r_l = Node.new(15)
grand_child_r_r = Node.new(7)
grand_child_l_l = Node.new(33)
child_r.left = grand_child_r_l
child_r.right = grand_child_r_r
child_l.left = grand_child_l_l
root.right = child_r
root.left = child_l

def bfs(node)
  queue = []
  queue.push(node)
  while(queue.size != 0)
    node = queue.shift
    p node.val
    children = [node.left, node.right].compact
    children.each do |child|
      queue.push(child)
    end
  end
end
bfs(root)
