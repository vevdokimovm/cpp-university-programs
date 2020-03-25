#lang racket
(define (abs x) 
  (cond ((>= x 0) x)
        (else (- x))))
(define (square x) (* x x))
(define (cube x) (* x x x))
(define (improve guess x) 
  (/ (+ (/ x (square guess)) (* 2 guess)) 3))
(define (good-enough? guess x)
  (< (abs (- (cube guess) x)) 0.0001))
(define (iter-cube-root guess x)
  (if (good-enough? guess x)
      guess
      (iter-cube-root (improve guess x) x)))
(define (cube-root x) (iter-cube-root 1.0 x))

(cube-root 46433)