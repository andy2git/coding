package com.andy.com.andy.lintcode;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

/**
 * Created by Andy on 4/16/16.
 */
public class Count1Binary {

    public int countOnes(int n) {
        int cnt = 0;

        while(n != 0){
            cnt++;
            n = n & (n-1);
        }
        return cnt;
    }

    @Test
    public void testNegative() {
        Count1Binary cb = new Count1Binary();
        assertEquals(32, cb.countOnes(-1));
    }

    @Test
    public void testPositive() {
        Count1Binary cb = new Count1Binary();
        assertEquals(2, cb.countOnes(5));
        assertEquals(2, cb.countOnes(3));
        assertEquals(1, cb.countOnes(1));
    }

    @Test
    public void testZero() {
        Count1Binary cb = new Count1Binary();
        assertEquals(0, cb.countOnes(0));
    }
}

