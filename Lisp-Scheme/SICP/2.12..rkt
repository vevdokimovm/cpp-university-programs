#lang racket

(define (make-interval a b)
  (cons a b))

(define (make-central-width c w)
  (make-interval (- c w) (+ c w)))

(define (lower-bound interval)
  (car interval))

(define (upper-bound interval)
  (cdr interval))

(define (center i)
  (/ (+ (lower-bound i) (upper-bound i)) 2))

(define (width i)
  (/ (- (upper-bound i) (lower-bound i)) 2))

(define (make-center-percent average w)
  (make-interval (* (- 1 (/ w 100)) average)
                 (* (+ 1 (/ w 100)) average)))

(define (percent interval)
  (* 100 (/ (width interval) (center interval))))

(define (print interval)
  (display (lower-bound interval))
  (display ", ")
  (display (upper-bound interval)))