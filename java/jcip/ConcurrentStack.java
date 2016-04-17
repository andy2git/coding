package com.andy.jcip;

import net.jcip.annotations.ThreadSafe;

import java.util.concurrent.atomic.AtomicReference;

@ThreadSafe
public class ConcurrentStack<E> {
    private static class Node<E> {
        private final E elem;
        private Node<E> next;

        private Node(E val) {
            this.elem = val;
        }

        public static <E> Node<E> of(E val) {
            Node<E> node = new Node<>(val);
            return node;
        }
    }

    private final AtomicReference<Node<E>> top = new AtomicReference<>();

    public void push(E element) {
        Node<E> newNode = Node.of(element);
        Node<E> oldNode = null;
        do {
            oldNode = top.get();
            newNode.next = oldNode;
        } while (!top.compareAndSet(oldNode, newNode));
    }

    public E pop() {
        Node<E> newNode = null;
        Node<E> oldNode = null;
        do {
            oldNode = top.get();
            if (oldNode == null) {
                return null;
            }
            newNode = oldNode.next;
        } while (!top.compareAndSet(oldNode, newNode));

        return oldNode.elem;
    }

    // TODO: need to make sure they work.
    // TODO: not super meaningful for ConcurrentContainer.
    // TODO: Not guaranteed, because top can be changed by other threads
    public boolean isEmpty() {
        return top.get() == null;
    }

    // TODO: need to make sure they work.
    public E peek () {
        Node<E> node = top.get();
        if(node == null) {
            return null;
        }
        return node.elem;
    }
}

