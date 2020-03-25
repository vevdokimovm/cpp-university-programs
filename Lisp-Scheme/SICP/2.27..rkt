#lang racket

(define (reverse items)
  (define (iter items result)
    (if (null? items)
        result
        (iter (cdr items) (cons (car items)
                                result))))
  (iter items null))

(define (deep-reverse items)
  (define (iter items result)
    (if (null? items)
        result
        (iter (cdr items) 
              (cons (if (not (pair? (car items)))
                        (car items)
                        (iter (car items) null))
                    result))))
  (iter items null))