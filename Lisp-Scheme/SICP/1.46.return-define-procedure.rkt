#lang racket

(define (iterative-improve good-enough? improve) 
  (define (iteration guess) 
    (let ((next (improve guess))) 
         (if (good-enough? guess next) 
             next 
             (iteration next)))) 
  iteration)

(define tolerance 0.00001)

(define (square x) (* x x))

(define (average x y) (/ (+ x y) 2.0))

(define (fixed-point f first-guess) 
  ((iterative-improve (lambda (guess next) 
                              (< (abs (- guess next)) 
                                 tolerance)) 
                      f) first-guess))
(define (sqrt x) 
  ((iterative-improve (lambda (guess next) 
                              (< (abs (- (square guess) x)) tolerance)) 
                      (lambda (guess) 
                              (average guess (/ x guess)))) 1.0))