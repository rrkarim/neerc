/*
	rkerimov@std.qu.edu.az
*/
import java.lang.System.*;
import java.util.*;	
import java.io.*;

class AComparator implements Comparator<Integer> {
    @Override
    public int compare(Integer i1, Integer i2) {
		if(Math.abs(i1) < Math.abs(i2)) return 0;
		return 1;
    }
}
class Pair {
    private final int x;
    private final int y;

    public Pair(final int x, final int y) {
        this.x = x;
        this.y = y;
    }
    @Override
    public boolean equals(final Object o) {
        if (this == o) return true;
        if (!(o instanceof Pair)) return false;
        final Pair pair = (Pair) o;
        if (x != pair.x) return false;
        if (y != pair.y) return false;
        return true;
    }
    @Override
    public int hashCode() {
        int result = x;
        result = 31 * result + y;
        return result;
    }
}

public class Answer { 
  
	public static int l1, l2, r1, r2, t1, t2, b1, b2, limit = 4000;
   	public static int gcd(int a, int b) {
		int c;
		while(a != 0) {
			c = a, a = b % a, b = c;
		}
		return b;
	}
	/*
		Add reflected points of destination
	*/
	public static void addPoints(List<Integer> listX, List<Integer> listY, int[] badguy_position, int[] captain_position, int distance) {
		int x = badguy_position[0], y = badguy_position[1];
		int cx = captain_position[0], cy = captain_position[1];
		for(int i = 0; i < limit; ++i) {
			listX.add(x - cx);
			if(i % 2 == 0) x += 2 * r2;
			else x += 2 * l2;
			if((x-cx) > distance) break;
		}
		x = badguy_position[0];
		for(int i = 0; i < limit; ++i) {
			if(i % 2 == 0) x -= 2 * l2;
			else x -= 2 * r2;
			listX.add(x-cx);
			if(x-cx < -distance) break;
		}
		///
		for(int i = 0; i < limit; ++i) {
			listY.add(y-cy);
			if(i % 2 == 0) y += 2 * t2;
			else y += 2 * b2;
			if(y-cy > distance) break;
		}
		y = badguy_position[1];
		for(int i = 0; i < limit; ++i) {
			if(i % 2 == 0) y -= 2 * b2;
			else y -= 2 * t2;
			listY.add(y-cy);
			if(y-cy < -distance) break;
		}
		Collections.sort(listX, new AComparator());
		Collections.sort(listY, new AComparator());
	}
	/*
		Add reflected points of init
	*/
	public static void addStartPoints(HashMap<Pair, Integer> startPoints, int[] captain_position, int distance) {
		int x = captain_position[0], y = captain_position[1];
		List<Integer> listX = new ArrayList<Integer>();
		List<Integer> listY = new ArrayList<Integer>();
		for(int i = 0; i < limit; ++i) {
			listX.add(x);
			if(i % 2 == 0) x += 2 * r1;
			else x += 2 * l1;
			if(x > distance) break;
		}
		x = captain_position[0];
		for(int i = 0; i < limit; ++i) {
			if(i % 2 == 0) x -= 2 * l1;
			else x -= 2 * r1;
			listX.add(x);
			if(x < -distance) break;
		}
		///
		for(int i = 0; i < limit; ++i) {
			listY.add(y);
			if(i % 2 == 0) y += 2 * t1;
			else y += 2 * b1;
			if(y > distance) break;
		}
		y = captain_position[1];
		for(int i = 0; i < limit; ++i) {
			if(i % 2 == 0) y -= 2 * b1;
			else y -= 2 * t1;
			listY.add(y);
			if(y < -distance) break;
		}
		for(Integer i : listX) {
			for(Integer j : listY) {
				Pair temp = new Pair(i, j);
				startPoints.put(temp, 1);
			}
		}
	}
	
	/*
		Add corners of every parallel rectangle
	*/
	public static  void addCorners(HashMap<Pair, Integer> startPoints, int w, int h, int distance) {
		List<Integer> listX = new ArrayList<Integer>();
		List<Integer> listY = new ArrayList<Integer>();
		int x = 0;
		for(int i = 0; i < limit; ++i) {
			listX.add(x);
			x += w;
			if(x > distance) break;
		}
		x = 0;
		for(int i = 0; i < limit; ++i) {
			x -= w;
			if(x < -distance) break;
			listX.add(x);
		}
		
		int y = 0;
		for(int i = 0; i < limit; ++i) {
			listY.add(y);
			y += h;
			if(y > distance) break;
		}
		y = 0;
		for(int i = 0; i < limit; ++i) {
			y -= h;
			if(y < -distance) break;
			listY.add(y);
		}
		
		for(Integer i : listX) {
			for(Integer j : listY) {
				Pair temp = new Pair(i, j);
				startPoints.put(temp, 1);
			}
		}
	}
	
    	public static int answer(int[] dimensions, int[] captain_position, int[] badguy_position, int distance) { 
		
		int w = dimensions[0], h = dimensions[1];
		
		l1 = captain_position[0]; r1 = w - captain_position[0];
		l2 = badguy_position[0]; r2 = w - badguy_position[0];
		
		t1 = h - captain_position[1]; b1 = captain_position[1];
		t2 = h - badguy_position[1]; b2 = badguy_position[1];
		
		
		List<Integer> listX = new ArrayList<Integer>(), listY = new ArrayList<Integer>();;
		
		addPoints(listX, listY, badguy_position, captain_position, distance);
		
		
		HashMap<Pair, Integer> startPoints = new HashMap<Pair, Integer>();
		HashMap<Pair, Integer> corners = new HashMap<Pair, Integer>();
		
		addStartPoints(startPoints, captain_position, distance);
		addCorners(startPoints, w, h, distance);
		
		
		int res = 0;
		HashMap<Pair, Integer> used = new HashMap<Pair, Integer>();
		for(Integer i : listX) {
			for(Integer j : listY) {
				if(i*i + j*j <= distance*distance) {
					if(i == 0 || j == 0) continue;
					int gcd_ = gcd(Math.abs(i), Math.abs(j));
					if(gcd_ == 0) continue;
					int xsdif = i / gcd_, ysdif = j / gcd_;
					Pair temp = new Pair(xsdif, ysdif);
					
					if(used.containsKey(temp)) continue;
					used.put(temp, 1);
						
					int x_ = captain_position[0], y_ = captain_position[1], foundError = 0;;
					Pair temp_;
					for(int z = 0; z < gcd_; ++z) {
						x_ += xsdif; y_ += ysdif;
						if(x_ == badguy_position[0] && y_ == badguy_position[1]) break; 
						temp_ = new Pair(x_, y_);
						if(startPoints.containsKey(temp_) || corners.containsKey(temp_)) {	
							foundError = 1;
							break;
						}
					}
					if(foundError == 1) continue;
					res += 1;
				}
			}
		}
		
		if(badguy_position[1] - captain_position[1] == 0 && Math.abs(badguy_position[0] - captain_position[0]) <= distance) res += 1;
		if(badguy_position[0] - captain_position[0] == 0 && Math.abs(badguy_position[1] - captain_position[1]) <= distance) res += 1;
		return res;	
    	}
    
	public static void main(String[] args) { 
		// some tests
		int[] dimensions = {6, 5};
		int[] captain_position = {4, 1};
		int[] badguy_position = {4, 3};
		int distance = 1;
		
		System.out.println(answer(dimensions, captain_position, badguy_position, distance));
    } 
}