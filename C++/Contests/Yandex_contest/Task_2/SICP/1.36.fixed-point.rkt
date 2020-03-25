#lang racket

(define tolerance 0.00001)

(define (fixed-point f first-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) tolerance))
  (define (try guess iteration)
    (display iteration)
    (display " : ")
    (display guess)
    (newline)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next (+ iteration 1)))))
  (try first-guess 0))

(define (f x)
  (/ (log 1000) (log x)))

(define (average a b)
  (/ (+ a b) 2.0))

(define (g x)
  (average x (f x)))