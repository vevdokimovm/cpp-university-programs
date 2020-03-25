#lang racket

(define (fringe tree)
  (define (processing tree result)
    (cond ((null? tree) result)
          ((not (pair? (car tree))) (processing (cdr tree) 
                                                (append result
                                                        (list (car tree)))))
          (else (append (processing (car tree) 
                                    null)
                        (processing (cdr tree)
                                    result)))))
  (processing tree `()))

(define x(list (list 1 2) (list 3 4)))