#lang racket

(define (make-accumulator initial)
  (lambda (addition) (begin (set! initial (+ initial addition))
                            initial)))

(define A (make-accumulator 5))
(define B (make-accumulator 10))