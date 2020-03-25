#lang racket

(define nil (list))

(define last-pair
  (lambda (ls)
    (define (onelem? list)
    (if (null? (cdr list))
        #t
        #f))
    (if (onelem? ls)
        (list (car ls))
        (last-pair (cdr ls)))))