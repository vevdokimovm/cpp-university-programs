#lang racket

(define (try guess x)
  (if (good-enough? guess x)
      guess
      (try (improve guess x) x)))

(define (average x y)
  (/ (+ x y) 2.0))

(define (improve guess x)
  (average guess (/ x guess)))

(define dx 0.00001)

(define (square x) (* x x))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) dx))

(define (sqrt x)
  (try 1.0 x))
