// Filename: vectors.rs

pub trait Vector2D<T> {
    fn scalar_multiplication(&mut self, s: T);
    fn add(&mut self, s: Vec<T>);
    fn subtraction(&mut self, s: Vec<T>);
}

pub trait Vector3D<T> {}

impl<T> Vector2D<T> for Vec<T>
where T: std::ops::Mul<Output = T> + Copy + std::ops::Add<Output = T> + std::ops::Sub<Output = T>
{
    // Vector components multiplication by a scalar value.
    // Formula: sa = (sa_{x} , sa_{y}, sa_{z})
    fn scalar_multiplication(&mut self, s: T) {
        for i in 0..self.len() {
            self[i] = self[i] * s;
        }
    }

    // Formula: a + b = [(a_{x} + b_{x}), (a_{y} + b_{y}), (a_{z} + b_{z})].
    fn add(&mut self, s: Vec<T>) {
        for i in 0..self.len() {
            self[i] = self[i] + s[i];
        }
    }

    // Formula: a - b = [(a_{x} - b_{x}), (a_{y} - b_{y}), (a_{z} - b_{z})].
    fn subtraction(&mut self, s: Vec<T>) {
        for i in 0..self.len() {
            self[i] = self[i] - s[i];
        }
    }
}

impl<T: std::ops::Mul<Output = T> + Copy> Vector3D<T> for Vec<T> {}






#[cfg(test)]
mod vectors_test {
    use super::*;

    #[test]
    fn scalar_multiplication_test() {
        let s = 2i32;
        let mut a: Vec<i32> = vec![1i32, 2i32, 3i32];
        a.scalar_multiplication(s); 
        assert_eq!(a, vec![2i32, 4i32, 6i32]);
    }

    #[test]
    fn add_test() {
        let s: Vec<i32> = vec![1i32, 2i32, 3i32];
        let mut a: Vec<i32> = vec![1i32, 2i32, 3i32];
        a.add(s);
        assert_eq!(a, vec![2i32, 4i32, 6i32]);
    }

    #[test]
    fn subtraction_test() {
        let s: Vec<i32> = vec![1i32, 2i32, 3i32];
        let mut a: Vec<i32> = vec![2i32, 4i32, 6i32];
        a.subtraction(s);
        assert_eq!(a, vec![1i32, 2i32, 3i32]);
    }
}
