class BoundedBuffer {
   final Lock lock = new ReentrantLock();
   final Condition notFull  = lock.newCondition(); 
   final Condition notEmpty = lock.newCondition(); 

   final Object[] items = new Object[100];
   int putptr, takeptr, count;

   public void put(Object x) throws InterruptedException {
     lock.lock();
     try {
       while (count == items.length)
         notFull.await();
       items[putptr] = x;
       if (++putptr == items.length) putptr = 0;
       ++count;
       notEmpty.signal();
     } finally {
       lock.unlock();
     }
   }

   public Object take() throws InterruptedException {
     lock.lock();
     try {
       while (count == 0)
         notEmpty.await();
       Object x = items[takeptr];
       if (++takeptr == items.length) takeptr = 0;
       --count;
       notFull.signal();
       return x;
     } finally {
       lock.unlock();
     }
   }
 }

----------------------------------------------------------

package com.andy.jcip;

import com.google.common.collect.Lists;
import net.jcip.annotations.GuardedBy;

import java.util.List;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class BoundedBuffer {
    @GuardedBy("lock") private final List<Integer> data;
    @GuardedBy("lock") private final int capacity;
    @GuardedBy("lock") private int size;
    @GuardedBy("lock") private int head;
    @GuardedBy("lock") private int tail;

    Lock lock = new ReentrantLock();
    private final Condition spaceCondition = lock.newCondition();
    private final Condition dataCondition = lock.newCondition();

    BoundedBuffer(int capacity) {
        this.data = Lists.newArrayListWithCapacity(capacity);
        this.capacity = capacity;
        size = 0;
        head = 0;
        tail = 0;
    }

    public void put(int x) throws InterruptedException {
        lock.lock();
        try {
            while (size == capacity) {
                spaceCondition.await();
            }
            data.add(head, x);
            head++;
            head %= capacity;
            size++;
            dataCondition.signalAll();
        } finally {
            lock.unlock();
        }
    }

    public int get() throws InterruptedException {
        lock.lock();
        try {
            while (size == 0) {
                dataCondition.await();
            }
            int x = data.get(tail);
            tail++;
            tail %= capacity;
            size--;
            spaceCondition.signalAll();
            return x;
        } finally {
            lock.unlock();
        }
    }
}

