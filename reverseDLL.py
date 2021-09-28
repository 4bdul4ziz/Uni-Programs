class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next


def printList(msg, head):

    print(msg + ": ", end='')
    while head:
        print(head.data, end=" —> ")
        head = head.next

    print("None")


def reverse(curr, k):

    prev = None

    while curr and k > 0:
        k = k - 1

        next = curr.next

        curr.next = prev

        prev = curr
        curr = next

    return prev, curr


def skipKNodes(curr, k):

    prev = None
    while curr and k > 0:
        k = k - 1
        prev = curr
        curr = curr.next

    return prev, curr


def reverseAlternatingKNodes(head, k):

    prev = None
    curr = head

    while curr:

        last = curr

        front, curr = reverse(curr, k)

        if prev is None:
            head = front

        else:
            prev.next = front

        last.next = curr

        prev, curr = skipKNodes(curr, k)

    return head


if __name__ == '__main__':

    head = None
    for i in reversed(range(10)):
        head = Node(i + 1, head)

    k = 5

    printList("Original linked list ", head)
    head = reverseAlternatingKNodes(head, k)
    printList("Resultant linked list", head)
