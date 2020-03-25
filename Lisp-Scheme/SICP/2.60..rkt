#lang racket

(define (list-to-set items)
  (define (clearing items left result)
    (cond ((null? items) result)
          ((and (not (element-of-set? (car items) left)))
           (clearing (cdr items)
                     (cons (car items) left)
                     (cons (car items) result)))
          (else (clearing (cdr items)
                          (cons (car items) left)
                          result))))
  (clearing items '() '()))
    
(define (element-of-set? x set)
  (cond ((null? set) #f)
        ((equal? x (car set)) #t)
        (else (element-of-set? x (cdr set)))))

(define (adjoin-set x set)
  (if (element-of-set? x (list-to-set set))
      set
      (cons x set)))


(define (intersection-set set1 set2)
  (define (inter set1 set2)
    (cond ((or (null? set1) (null? set2)) '())
          ((element-of-set? (car set1) set2)
           (cons (car set1)
                 (intersection-set (cdr set1) set2)))
          (else (intersection-set (cdr set1) set2))))
  (inter (list-to-set set1)
         (list-to-set set2)))

(define (union-set set1 set2)
  (define (union set1 set2)
    (cond ((null? set1) set2)
          ((element-of-set? (car set1) set2)
           (union-set (cdr set1) set2))
          (else (cons (car set1)
                      (union-set (cdr set1) set2)))))
  (union (list-to-set set1)
         (list-to-set set2)))


(define (element-of-set? x set)
  (cond ((null? set) #f)
        ((equal? x (car set)) #t)
        (else (element-of-set? x (cdr set)))))

(define (adjoin-set x set)
  (cons x set))

(define (union-set2 set1 set2)
  (append set1 set2))