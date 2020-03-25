#lang racket

(define (improvement x enough? improve)
  (if (enough? x (improve x))
      (improve x)
      (improvement (improve x) enough? improve)))
      
      
(define (iterative-improve enough? improve)
  (lambda (x) (improvement x enough? improve)))

(define (fixed-point f)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) 0.00001))
  (iterative-improve close-enough? f))

(define (average-damp f)
  (define (average x y) (/ (+ x y) 2.0))
  (lambda (x) (average x (f x))))

(define (sqrt x)
  ((fixed-point (average-damp (lambda (y) (/ x y)))) x))